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
#include "../Utils//DrawTriangleUtil.h"

using namespace std;

class DrawTexture {
public:
    DrawTriangleUtil *drawTriangleUtil;

    int Draw();
};


#endif //TESTOPENGL_SLN_DRAWTEXTURE_H
