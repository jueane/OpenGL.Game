#include <iostream>
#include "glad.c"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	cout << "reset window size" << endl;
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

// shader vertex
const char *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 vertexColor;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"	vertexColor=aColor;\n"
"}\0";

const char *fragmentShaderSource = "#version 330 core\n"
"in vec3 vertexColor;"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"	FragColor=vec4(vertexColor,1);\n"
//"	FragColor=outColor;\n"
"}\n\0";

void renderer() {

}

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Test OpenGL", NULL, NULL);

	if (window == NULL) {
		cout << "create gl window failed" << endl;
		glfwTerminate();
		return -1;
	}else{


	cout<<"hi"<<endl;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "failed init glad" << endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//glShaderSource(vertexShader, 1, vertexShaderSource, NULL);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	int success;
	char infolog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
		cout << "error::shader::vertex:compilation_failed" << endl;
	}

	// shader fragment
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	// 附加
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// 检查错误
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
		cout << "error::shader::program:compilation_failed" << endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//float vertices[] = {
	//	-0.5,-0.5,0,
	//	0.5,-0.5,0,
	//	0,0.5,0
	//};
	float vertices[] = {
		0.5f, 0.5f, 0.0f,		1,0,0,   // 右上角
		0.5f, -0.5f, 0.0f,		0,1,0,  // 右下角
		-0.4f, -0.5f, 0.0f,	0,0,1, // 左下角
		-0.5f, 0.5f, 0.0f,		1,0,0   // 左上角
	};

	unsigned int indices[] = {
		0,1,3,
		1,2,3
	};

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);


	//glBindBuffer(GL_ARRAY_BUFFER,0);
	//glBindVertexArray(0);






	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glUseProgram(shaderProgram);
	// Draw a triangle
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	// Draw a rectangle

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glfwSwapBuffers(window);

	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	cout << "Support vertex attributes count: " << nrAttributes << endl;

	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		//glClearColor(0.3, 0.3, 0.5, 1);
		//glClear(GL_COLOR_BUFFER_BIT);

		//renderer
		glUseProgram(shaderProgram);


		//float timeValue = glfwGetTime();
		//float greenValue = (sin(timeValue) / 2) + 0.5;
		//int vertexColorLocation = glGetUniformLocation(shaderProgram, "outColor");
		//glUniform4f(vertexColorLocation, 1-greenValue, greenValue, 0, 1);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);

		//glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}