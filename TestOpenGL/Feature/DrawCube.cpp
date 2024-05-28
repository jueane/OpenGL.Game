//
// Created by Administrator on 2024/5/25.
//

#include "DrawCube.h"
#include "../Utils/WindowUtil.h"

int DrawCube::Draw() {
    cout << "绘制贴图" << endl;

    auto window = WindowUtil::createWindowUtil(800, 600);

    glEnable(GL_DEPTH_TEST);

    float vertices[] = {
            -0.5f, -0.5f, -0.5f, 1, 0, 0, 0.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 0, 1, 0, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 0, 0, 1, 1.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 1, 0, 0, 1.0f, 1.0f,
            -0.5f, 0.5f, -0.5f, 0, 1, 0, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0, 0, 1, 0.0f, 0.0f,

            -0.5f, -0.5f, 0.5f, 1, 0, 0, 0.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 0, 1, 0, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 0, 0, 1, 1.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 1, 0, 0, 1.0f, 1.0f,
            -0.5f, 0.5f, 0.5f, 0, 1, 0, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0, 0, 1, 0.0f, 0.0f,

            -0.5f, 0.5f, 0.5f, 1, 0, 0, 1.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 0, 1, 0, 1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0, 0, 1, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 1, 0, 0, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0, 1, 0, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 0, 0, 1, 1.0f, 0.0f,

            0.5f, 0.5f, 0.5f, 1, 0, 0, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 0, 1, 0, 1.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0, 0, 1, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 1, 0, 0, 0.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 0, 1, 0, 0.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 0, 0, 1, 1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f, 1, 0, 0, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0, 1, 0, 1.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 0, 0, 1, 1.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1, 0, 0, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0, 1, 0, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 0, 0, 1, 0.0f, 1.0f,

            -0.5f, 0.5f, -0.5f, 1, 0, 0, 0.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 0, 1, 0, 1.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 0, 0, 1, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1, 0, 0, 1.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 0, 1, 0, 0.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 0, 0, 1, 0.0f, 1.0f
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

    drawTriangleUtil = new DrawTriangleUtil(8, vertices, sizeof(vertices), indices, sizeof(indices));


    // 使用纹理
    auto texture = new TextureUtil("resources\\textures\\container.jpg", false);
    auto texture2 = new TextureUtil("resources\\textures\\awesomeface.png", true);


    auto shader = new ShaderUtil("Shader\\shader3_cube.vert",
                                 "Shader\\shader3_cube.frag");
    shader->Use();

    shader->setInt("ourTexture1", 0);
    shader->setInt("texture2", 1);

    glm::vec3 cubePositions[] = {
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(2.0f, 5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3(2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f, 3.0f, -7.5f),
            glm::vec3(1.3f, -2.0f, -2.5f),
            glm::vec3(1.5f, 2.0f, -2.5f),
            glm::vec3(1.5f, 0.2f, -1.5f),
            glm::vec3(-1.3f, 1.0f, -1.5f)
    };

    glfwSwapBuffers(window);
    while (!glfwWindowShouldClose(window)) {
        CameraTemp::processInput(window);

        glClearColor(0.3, 0.3, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        texture->active(0);
        texture2->active(1);

        // 模型矩阵:放倒
//        glm::mat4 model = glm::mat4(1.0f);
//        model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

        // 观察矩阵
//        glm::mat4 view = glm::mat4(1.0f);
//        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

        // 摄像机
//        cameraPos = glm::vec3(0.0f, 0.0f, 10.0f);
        glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
//        auto cameraDirection = glm::normalize(cameraPos - cameraTarget);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
//        glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
//        glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);


// 自动移动摄像机
//        auto radius = 30.0f;
//        cameraPos.x = sin(glfwGetTime()) * radius;
//        cameraPos.z = cos(glfwGetTime()) * radius;

        glm::mat4 view;
        view = glm::lookAt(CameraTemp::cameraPos, CameraTemp::cameraPos + CameraTemp::cameraFront, up);


        // 透视矩阵
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(CameraTemp::fov),
                                      (float) WindowUtil::width / WindowUtil::height,
                                      0.1f, 100.0f);

//        shader->setMatrix("model", model);
        shader->setMatrix("view", view);
        shader->setMatrix("projection", projection);


        for (int i = 10; i > 0; i--) {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::scale(model, glm::vec3(0.2f * (i + 1), 0.2f * (i + 1), 0.2f * (i + 1)));
            model = glm::translate(model, cubePositions[i]);

            auto rotInAxis = glm::vec3(0.0f, 0.0f, 0.0f);
            auto aa = i % 3;
            if (aa == 0) {
                rotInAxis.x = 1.0f;
            } else if (aa == 1) {
                rotInAxis.y = 1.0f;
            } else {
                rotInAxis.z = 1.0f;
            }
//            model = glm::rotate(model, (float) glfwGetTime() * i, rotInAxis);

            shader->setMatrix("model", model);
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        }


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete drawTriangleUtil;

    glfwTerminate();
    return 0;
}
