//
// Created by Administrator on 2024/5/28.
//

#include "DrawCubeInstance.h"
#include <assimp/postprocess.h>
#include <iostream>
#include "../Utils/WindowUtil.h"

int DrawCubeInstance::draw() {

    cout << "绘制贴图" << endl;

    auto window = WindowUtil::createWindowUtil(800, 600);

    glEnable(GL_DEPTH_TEST);

    float vertices[] = {
            -0.5f, -0.5f, -0.5f, 1, 0, 0, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
            0.5f, -0.5f, -0.5f, 0, 1, 0, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
            0.5f, 0.5f, -0.5f, 0, 0, 1, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
            0.5f, 0.5f, -0.5f, 1, 0, 0, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
            -0.5f, 0.5f, -0.5f, 0, 1, 0, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f,
            -0.5f, -0.5f, -0.5f, 0, 0, 1, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,

            -0.5f, -0.5f, 0.5f, 1, 0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 0, 1, 0, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 0, 0, 1, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 1, 0, 0, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
            -0.5f, 0.5f, 0.5f, 0, 1, 0, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0, 0, 1, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,

            -0.5f, 0.5f, 0.5f, 1, 0, 0, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 0, 1, 0, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 0, 0, 1, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 1, 0, 0, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0, 1, 0, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 0, 0, 1, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,

            0.5f, 0.5f, 0.5f, 1, 0, 0, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 0, 1, 0, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 0, 0, 1, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 1, 0, 0, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 0, 1, 0, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 0, 0, 1, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,

            -0.5f, -0.5f, -0.5f, 1, 0, 0, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 0, 1, 0, 1.0f, 1.0f, 0.0f, -1.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 0, 0, 1, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1, 0, 0, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0, 1, 0, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 0, 0, 1, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,

            -0.5f, 0.5f, -0.5f, 1, 0, 0, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 0, 1, 0, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 0, 0, 1, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1, 0, 0, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 0, 1, 0, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 0, 0, 1, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f
    };
    unsigned int indices[] = {
            0, 1, 2,
            3, 4, 5,
            6, 7, 8,
            9, 10, 11,
            12, 13, 14,
            15, 16, 17,
            18, 19, 20,
            21, 22, 23,
            24, 25, 26,
            27, 28, 29,
            30, 31, 32,
            33, 34, 35
    };


    // 使用纹理
    auto texture = new TextureUtil("resources\\textures\\container.jpg", false);
    auto texture2 = new TextureUtil("resources\\textures\\awesomeface.png", true);
    auto texture3 = new TextureUtil("resources\\textures\\container2.png", true);
    auto texture4_specular = new TextureUtil("resources\\textures\\container2_specular.png", true);

    texture->active(0);
    texture2->active(1);
    texture3->active(2);
    texture4_specular->active(3);


    auto lightShader = new ShaderUtil("Shader\\shader4_light.vert",
                                      "Shader\\shader4_light.frag");

    auto cubeShader = new ShaderUtil("Shader\\shader6_intance.vert",
                                     "Shader\\shader6_intance.frag");

//    drawTriangleUtil = new DrawTriangleUtil(11, vertices, sizeof(vertices), indices, sizeof(indices));
    drawTriangleInstanceUtil = new DrawTriangleInstanceUtil(11, vertices, sizeof(vertices), indices, sizeof(indices));

    int m = 100;
    int n = 1000;
    int len = m * n;
    glm::vec3 *posArray = new glm::vec3[len];

    // 生成位置
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int index=i*m+j;
            posArray[index].x = i*2;
            posArray[index].y = 0;
            posArray[index].z = j*2;
        }
    }

    drawTriangleInstanceUtil->setPosArray(posArray, len);


    while (!glfwWindowShouldClose(window)) {
        CameraTemp::processInput(window);

        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
//        auto cameraDirection = glm::normalize(cameraPos - cameraTarget);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

        glm::mat4 view;
        view = glm::lookAt(CameraTemp::cameraPos, CameraTemp::cameraPos + CameraTemp::cameraFront, up);

        // 透视矩阵
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(CameraTemp::fov),
                                      (float) WindowUtil::width / WindowUtil::height,
                                      0.1f, 100.0f);


        glm::mat4 model = glm::mat4(1.0f);

        cubeShader->Use();
        cubeShader->setMatrix("view", view);
        cubeShader->setMatrix("projection", projection);
        cubeShader->setMatrix("model", model);

//        drawTriangleUtil->Draw();
        drawTriangleInstanceUtil->Draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}
