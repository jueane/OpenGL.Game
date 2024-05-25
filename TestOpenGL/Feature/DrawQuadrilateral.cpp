//
// Created by Administrator on 2024/5/26.
//

#include "DrawQuadrilateral.h"

#include "DrawQuadrilateral.h"


void DrawQuadrilateral::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    cout << "reset window size" << endl;
    glViewport(0, 0, width, height);
}

void DrawQuadrilateral::processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int DrawQuadrilateral::Draw() {
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
    glfwSetFramebufferSizeCallback(window, DrawQuadrilateral::framebuffer_size_callback);
    auto shader = new ShaderUtil("Shader\\shader1.vert",
                                 "Shader\\shader1.frag");

    float vertices[] = {
            0.5f, 0.5f, 0.0f, 1, 0, 0,     // 右上角
            0.5f, -0.5f, 0.0f, 0, 1, 0,     // 右下角
            -0.4f, -0.5f, 0.0f, 0, 0, 1, // 左下角
            -0.5f, 0.5f, 0.0f, 1, 0, 0     // 左上角
    };

    unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3};

    drawTriangleUtil = new DrawTriangleUtil(6, vertices, sizeof(vertices), indices, sizeof(indices));

    shader->Use();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
    while (!glfwWindowShouldClose(window)) {
        this->processInput(window);

        glClearColor(0.3, 0.3, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete drawTriangleUtil;

    glfwTerminate();
    return 0;
}
