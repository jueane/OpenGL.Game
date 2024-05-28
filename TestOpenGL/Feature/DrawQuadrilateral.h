//
// Created by Administrator on 2024/5/26.
//

#ifndef TESTOPENGL_SLN_DRAWQUADRILATERAL_H
#define TESTOPENGL_SLN_DRAWQUADRILATERAL_H

#include "../Utils/TextureUtil.h"
#include "../Utils/ShaderUtil.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "../Utils/DrawTriangleUtil.h"


using namespace std;

class DrawQuadrilateral {
public:
    DrawTriangleUtil *drawTriangleUtil;

    int Draw();

private:
};


#endif //TESTOPENGL_SLN_DRAWQUADRILATERAL_H
