//
// Created by Administrator on 2024/5/25.
//

#ifndef TESTOPENGL_SLN_DRAWCUBECOLOR_H
#define TESTOPENGL_SLN_DRAWCUBECOLOR_H

#include "../Utils/TextureUtil.h"
#include "../Utils/ShaderUtil.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <stb_image.h>
#include "CameraTemp.h"
#include "../Utils/DrawTriangleUtil.h"

class DrawCubeColor {
public:
    DrawTriangleUtil *drawTriangleUtil;
    DrawTriangleUtil *drawTriangleUtil2;

    int Draw();
};


#endif //TESTOPENGL_SLN_DRAWCUBECOLOR_H
