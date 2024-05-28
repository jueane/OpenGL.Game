//
// Created by Administrator on 2024/5/25.
//

#include "TestLoadModel.h"
#include <iostream>
#include "../Utils/Model/Model.h"
#include "../Utils/WindowUtil.h"

int TestLoadModel::Draw() {
    cout << "加载模型" << endl;

    auto window = WindowUtil::createWindowUtil(800, 600);

    glEnable(GL_DEPTH_TEST);


    auto modelShader = new ShaderUtil("Shader\\shader5_model.vert", "Shader\\shader5_model.frag");
    modelShader->Use();


    auto model = Model(R"(resources\objects\nanosuit\nanosuit.obj)");


    while (!glfwWindowShouldClose(window)) {
        CameraTemp::processInput(window);

        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 view;
        view = glm::lookAt(CameraTemp::cameraPos, CameraTemp::cameraPos + CameraTemp::cameraFront, up);

        // 透视矩阵
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(CameraTemp::fov),
                                      (float) WindowUtil::width / WindowUtil::height,
                                      0.1f, 100.0f);

        glm::mat4 myModel = glm::mat4(1.0f);
        modelShader->setMatrix("projection", projection);
        modelShader->setMatrix("view", view);
        modelShader->setMatrix("model", myModel);
        model.Draw(*modelShader);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete drawTriangleUtil;

    glfwTerminate();
    return 0;
}
