//
// Created by Administrator on 2021/12/25.
//

#ifndef TESTOPENGL_DRAWTRIANGLE_CPP
#define TESTOPENGL_DRAWTRIANGLE_CPP

#include "../Utils/ShaderUtil.h"
#include "../glad.c"
#include "DrawTriangle.h"

DrawTriangle::DrawTriangle()
{
}

void DrawTriangle::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    cout << "reset window size" << endl;
    glViewport(0, 0, width, height);
}

void DrawTriangle::processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

int DrawTriangle::Draw()
{
    auto err = glfwInit();
    cout << "init result " << err << endl;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow *window = glfwCreateWindow(800, 600, "Test OpenGL", NULL, NULL);
    if (window == NULL)
    {
        cout << "create gl window failed" << endl;
        glfwTerminate();
        return -1;
    } else
    {
        cout << "Window created" << endl;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        cout << "failed init glad" << endl;
        return -1;
    }
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, DrawTriangle::framebuffer_size_callback);
//    auto shader = new ShaderUtil("..\\TestOpenGL\\Shader\\shader1.vert",
//                             "..\\TestOpenGL\\Shader\\shader1.frag");
    auto shader = new ShaderUtil("D:\\develop\\cpp\\OpenGL.Game\\TestOpenGL\\Shader\\shader1.vert",
                                 "D:\\develop\\cpp\\OpenGL.Game\\TestOpenGL\\Shader\\shader1.frag");

    //float vertices[] = {
    //	-0.5,-0.5,0,
    //	0.5,-0.5,0,
    //	0,0.5,0
    //};
    float vertices[] = {
            0.5f, 0.5f, 0.0f, 1, 0, 0,     // 右上角
            0.5f, -0.5f, 0.0f, 0, 1, 0,     // 右下角
            -0.4f, -0.5f, 0.0f, 0, 0, 1, // 左下角
            -0.5f, 0.5f, 0.0f, 1, 0, 0     // 左上角
    };

    unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3};

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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //glBindBuffer(GL_ARRAY_BUFFER,0);
    //glBindVertexArray(0);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    shader->Use();

    // Draw a triangle
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    // Draw a rectangle

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    cout << "Support vertex attributes count: " << nrAttributes << endl;
    while (!glfwWindowShouldClose(window))
    {
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

#endif