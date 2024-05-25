//
// Created by Administrator on 2024/4/26.
//

#include "DrawTexture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

    this->width = 800;
    this->height = 600;

    GLFWwindow *window = glfwCreateWindow(this->width, this->height, "Test OpenGL", NULL, NULL);
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

    shader->setInt("ourTexture1", 0);
    shader->setInt("texture2", 1);


    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
    while (!glfwWindowShouldClose(window)) {
        this->processInput(window);

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
        projection = glm::perspective(glm::radians(45.0f), (float) this->width / this->height, 0.1f, 100.0f);

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
