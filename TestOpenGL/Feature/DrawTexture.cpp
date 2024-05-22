//
// Created by Administrator on 2024/4/26.
//

#include "DrawTexture.h"

DrawTexture::DrawTexture() {

}

void DrawTexture::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    cout << "reset window size" << endl;
    glViewport(0, 0, width, height);
}

void DrawTexture::processInput(GLFWwindow *window) {

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int DrawTexture::Draw() {

    cout << "绘制贴图" << endl;
    auto err = glfwInit();
    cout << "init result " << err << endl;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow *window = glfwCreateWindow(800, 600, "Test OpenGL", NULL, NULL);
    if (window == NULL) {
        cout << "create gl window failed" << endl;
        glfwTerminate();
        return -1;
    } else {
        cout << "Window created" << endl;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        cout << "failed init glad" << endl;
        return -1;
    }

    // 输出支持的顶点数量
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    cout << "Support vertex attributes count: " << nrAttributes << endl;

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, DrawTexture::framebuffer_size_callback);
    auto shader = new ShaderUtil("Shader\\shader2_texture\\shader1.vert",
                                 "Shader\\shader2_texture\\shader1.frag");

    //float vertices[] = {
    //	-0.5,-0.5,0,
    //	0.5,-0.5,0,
    //	0,0.5,0
    //};
    float vertices[] = {
            0.5f, 0.5f, 0.0f, 1, 0, 0, 1.0f, 1.0f,    // 右上角
            0.5f, -0.5f, 0.0f, 0, 1, 0, 1.0f, 0.0f,    // 右下角
            -0.4f, -0.5f, 0.0f, 0, 0, 1, 0.0f, 0.0f, // 左下角
            -0.5f, 0.5f, 0.0f, 1, 0, 0, 0.0f, 1.0f  // 左上角
    };

    unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3};

    float texCoords[] = {
            0.0, 0.0, // 左下角
            1.0, 0.0, // 右下角
            0.5, 1.0 // 上中
    };
//    glTexParameteri()


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

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    // 使用纹理
    unsigned int texture;
    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0); // 在绑定纹理之前先激活纹理单元
    glBindTexture(GL_TEXTURE_2D, texture);
    // 为当前绑定的纹理对象设置环绕、过滤方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load("resources\\textures\\container.jpg", &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);



    // texture 2
    // ---------
    unsigned int texture2;
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                    GL_REPEAT);    // set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    data = stbi_load(("resources/textures/awesomeface.png"), &width, &height, &nrChannels, 0);
    if (data) {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    shader->Use();

    glUniform1i(glGetUniformLocation(shader->ID, "ourTexture1"), 0);
    glUniform1i(glGetUniformLocation(shader->ID, "texture2"), 1);


    glActiveTexture(GL_TEXTURE0); // 在绑定纹理之前先激活纹理单元
    glBindTexture(GL_TEXTURE_2D, texture);

    glActiveTexture(GL_TEXTURE1); // 在绑定纹理之前先激活纹理单元
    glBindTexture(GL_TEXTURE_2D, texture2);

//    shader->setInt("textur2",1);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
    while (!glfwWindowShouldClose(window)) {
        this->processInput(window);

        //glClearColor(0.3, 0.3, 0.5, 1);
        //glClear(GL_COLOR_BUFFER_BIT);

        //renderer
//        glUseProgram(shaderProgram);

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
