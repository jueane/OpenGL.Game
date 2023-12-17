//
// Created by Administrator on 2021/12/25.
//

#ifndef TESTOPENGL_DRAWTRIANGLE_H
#define TESTOPENGL_DRAWTRIANGLE_H

#include "../Utils/TextureUtil.h"
#include "../Utils/ShaderUtil.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

using namespace std;

class DrawTriangle
{
public:
    DrawTriangle();

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    void processInput(GLFWwindow *window);

    int Draw();

private:
};

#endif
