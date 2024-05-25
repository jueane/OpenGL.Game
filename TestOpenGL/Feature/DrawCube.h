//
// Created by Administrator on 2024/5/25.
//

#ifndef TESTOPENGL_SLN_DRAWCUBE_H
#define TESTOPENGL_SLN_DRAWCUBE_H

#include "../Utils/TextureUtil.h"
#include "../Utils/ShaderUtil.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class DrawCube {
public:
    int width = 800;
    int height = 600;

    float deltaTime;
    float lastFrame = 0.0f; // 上一帧的时间

    static void mouse_callback(GLFWwindow *window, double xposIn, double yposIn);

    static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    void processInput(GLFWwindow *window);

    int Draw();
};


#endif //TESTOPENGL_SLN_DRAWCUBE_H
