//
// Created by Administrator on 2024/5/25.
//

#include "DrawCubeColor.h"
#include "../Utils/DrawTriangleUtil.h"

void DrawCubeColor::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    cout << "reset window size" << endl;
    glViewport(0, 0, width, height);
}

int DrawCubeColor::Draw() {
    cout << "绘制贴图" << endl;

    auto err = glfwInit();

    cout << "init result " << err << endl;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow *window = glfwCreateWindow(this->width, this->height, "Test OpenGL", NULL, NULL);
    if (window == NULL) {
        cout << "create gl window failed" << endl;
        glfwTerminate();
        return -1;
    } else {
        cout << "Window created" << endl;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, DrawCubeColor::framebuffer_size_callback);

    glfwSetCursorPosCallback(window, CameraTemp::mouse_callback);
    glfwSetScrollCallback(window, CameraTemp::scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        cout << "failed init glad" << endl;
        return -1;
    }

    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    cout << "Support vertex attributes count: " << nrAttributes << endl;

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


    auto shader = new ShaderUtil("Shader\\shader3.vert",
                                 "Shader\\shader3.frag");

    auto lightShader = new ShaderUtil("Shader\\shader3.vert",
                                      "Shader\\light.frag");

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

        glClearColor(0.0f, 0.0f, 0.0f, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        drawTriangleUtil->Draw();

        glActiveTexture(GL_TEXTURE0); // 在绑定纹理之前先激活纹理单元
        glBindTexture(GL_TEXTURE_2D, texture->texture);

        glActiveTexture(GL_TEXTURE1); // 在绑定纹理之前先激活纹理单元
        glBindTexture(GL_TEXTURE_2D, texture2->texture);


        // 模型矩阵:放倒
//        glm::mat4 lightModel = glm::mat4(1.0f);
//        lightModel = glm::rotate(lightModel, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

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


        glm::mat4 view;
        view = glm::lookAt(CameraTemp::cameraPos, CameraTemp::cameraPos + CameraTemp::cameraFront, up);

        // 透视矩阵
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(CameraTemp::fov), (float) this->width / this->height, 0.1f, 100.0f);

        shader->Use();
        shader->setMatrix("view", view);
        shader->setMatrix("projection", projection);

        shader->setVec3("objectColor", 1.0f, 0.5f, 0.31f);
        shader->setVec3("lightColor", 1.0f, 1.0f, 1.0f);


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
//            lightModel = glm::rotate(lightModel, (float) glfwGetTime() * i, rotInAxis);

            shader->setMatrix("model", model);
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        }

//        drawTriangleUtil->Draw();

        lightShader->Use();

        glm::mat4 lightModel = glm::mat4(1.0f);
        lightModel= glm::translate(lightModel, glm::vec3(2,2,0));
        lightShader->setMatrix("model", lightModel);
        lightShader->setMatrix("view", view);
        lightShader->setMatrix("projection", projection);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


        // 灯光
//        unsigned int lightVAO;
//        glGenVertexArrays(1, &lightVAO);
//        glBindVertexArray(lightVAO);
//        // 只需要绑定VBO不用再次设置VBO的数据，因为箱子的VBO数据中已经包含了正确的立方体顶点数据
//        unsigned int VBO;
//        glBindBuffer(GL_ARRAY_BUFFER, VBO);
//        // 设置灯立方体的顶点属性（对我们的灯来说仅仅只有位置数据）
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
//        glEnableVertexAttribArray(0);



        // 绘制灯立方体对象
//        glBindVertexArray(lightVAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete drawTriangleUtil;

    glfwTerminate();
    return 0;
}
