//
// Created by Administrator on 2024/4/26.
//

#ifndef TESTOPENGL_SLN_DRAWTEXTURE_H
#define TESTOPENGL_SLN_DRAWTEXTURE_H

#include "../Utils/TextureUtil.h"
#include "../Utils/ShaderUtil.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <stb_image.h>

using namespace std;

class DrawTexture {
public:
    DrawTexture();

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    void processInput(GLFWwindow *window);

    int Draw();
};


#endif //TESTOPENGL_SLN_DRAWTEXTURE_H
