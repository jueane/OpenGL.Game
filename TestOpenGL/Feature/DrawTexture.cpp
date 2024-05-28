//
// Created by Administrator on 2024/4/26.
//

#include "DrawTexture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Utils/WindowUtil.h"
#include "CameraTemp.h"

int DrawTexture::Draw() {
    cout << "绘制贴图" << endl;

    auto window = WindowUtil::createWindowUtil(800, 600);

    auto shader = new ShaderUtil("Shader\\shader2_texture.vert",
                                 "Shader\\shader2_texture.frag");

    float vertices[] = {
            0.5f, 0.5f, 0.0f, 1, 0, 0, 1.0f, 1.0f,    // 右上角
            0.5f, -0.5f, 0.0f, 0, 1, 0, 1.0f, 0.0f,    // 右下角
            -0.4f, -0.5f, 0.0f, 0, 0, 1, 0.0f, 0.0f, // 左下角
            -0.5f, 0.5f, 0.0f, 1, 0, 0, 0.0f, 1.0f  // 左上角
    };

    unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3};

    drawTriangleUtil = new DrawTriangleUtil(8, vertices, sizeof(vertices), indices, sizeof(indices));


    // 使用纹理
    auto texture = new TextureUtil("resources\\textures\\container.jpg", false);
    auto texture2 = new TextureUtil("resources\\textures\\awesomeface.png", true);


    shader->Use();

    shader->setInt("ourTexture1", texture->texture_index);
    shader->setInt("texture2", texture2->texture_index);


    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
    while (!glfwWindowShouldClose(window)) {
        CameraTemp::processInput(window);

        glClearColor(0.3, 0.3, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0); // 在绑定纹理之前先激活纹理单元
        glBindTexture(GL_TEXTURE_2D, texture->texture);

        glActiveTexture(GL_TEXTURE1); // 在绑定纹理之前先激活纹理单元
        glBindTexture(GL_TEXTURE_2D, texture2->texture);


        // 模型矩阵:放倒
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

        // 观察矩阵
        glm::mat4 view = glm::mat4(1.0f);
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

        // 透视矩阵
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(CameraTemp::fov),
                                      (float) WindowUtil::width / WindowUtil::height,
                                      0.1f, 100.0f);

        shader->setMatrix("model", model);
        shader->setMatrix("view", view);
        shader->setMatrix("projection", projection);

        // 位移和旋转
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
        trans = glm::rotate(trans, (float) glfwGetTime(), glm::vec3(0.0, 0.0, 1.0));

        trans = model * trans;

        shader->setMatrix("transform", trans);


        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    delete drawTriangleUtil;

    glfwTerminate();
    return 0;
}
