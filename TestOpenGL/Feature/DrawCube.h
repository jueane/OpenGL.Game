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
#include "CameraTemp.h"
#include "../Utils/DrawTriangleUtil.h"

class DrawCube {
public:
    int width = 800;
    int height = 600;

    DrawTriangleUtil *drawTriangleUtil;

//    static void mouse_callback(GLFWwindow *window, double xposIn, double yposIn);

//    static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

//    void processInput(GLFWwindow *window);

    int Draw();
};


#endif //TESTOPENGL_SLN_DRAWCUBE_H
