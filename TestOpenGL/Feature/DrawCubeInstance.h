//
// Created by Administrator on 2024/5/28.
//

#ifndef TESTOPENGL_SLN_DRAWCUBEINSTANCE_H
#define TESTOPENGL_SLN_DRAWCUBEINSTANCE_H

#include "../Utils/TextureUtil.h"
#include "../Utils/ShaderUtil.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <stb_image.h>
#include "CameraTemp.h"
#include "../Utils/DrawTriangleUtil.h"
#include "../Utils/DrawTriangleInstanceUtil.h"

class DrawCubeInstance {
public:
    DrawTriangleUtil *drawTriangleUtil;
    DrawTriangleInstanceUtil *drawTriangleInstanceUtil;

    int draw();
};


#endif //TESTOPENGL_SLN_DRAWCUBEINSTANCE_H
