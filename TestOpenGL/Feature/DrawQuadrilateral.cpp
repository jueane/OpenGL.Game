//
// Created by Administrator on 2024/5/26.
//

#include "DrawQuadrilateral.h"

#include "DrawQuadrilateral.h"
#include "../Utils/WindowUtil.h"
#include "CameraTemp.h"


int DrawQuadrilateral::Draw() {

    auto window = WindowUtil::createWindowUtil(800, 600);


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
        CameraTemp::processInput(window);

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
