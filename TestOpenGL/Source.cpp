#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 300, "Test OpenGL", NULL, NULL);

	if (window == NULL) {
		cout << "create gl window failed" << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "failed init glad" << endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);


	int a;
	cin >> a;

	return 0;
}