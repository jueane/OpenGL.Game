//
// Created by Administrator on 2024/5/25.
//

#ifndef TESTOPENGL_SLN_DRAWCUBESTENCILTEST_H
#define TESTOPENGL_SLN_DRAWCUBESTENCILTEST_H

#include "../Utils/TextureUtil.h"
#include "../Utils/ShaderUtil.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <stb_image.h>
#include "CameraTemp.h"
#include "../Utils/DrawTriangleUtil.h"

class DrawCubeStencilTest
{
public:
    DrawTriangleUtil *drawTriangleUtil;

    int Draw();

    void Draw1(glm::vec3 cubePositions[], ShaderUtil *shader, float scale);
};

#endif // TESTOPENGL_SLN_DRAWCUBESTENCILTEST_H
