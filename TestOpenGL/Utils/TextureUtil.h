//
// Created by Administrator on 2021/12/25.
//

#ifndef TESTOPENGL_TEXTUREUTIL_H
#define TESTOPENGL_TEXTUREUTIL_H

//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
#include <string>
#include <iostream>

//#include "../glad.c"
//#include <GLFW/glfw3.h>

//#include "../glad.c"

//#ifndef STB_IMAGE_IMPLEMENTATION
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//#endif


class TextureUtil
{
public:
    unsigned int texture;

    int width, height, nrChannels;

    unsigned char *data;

    TextureUtil(const char *path);

    ~TextureUtil();
};

#endif //TESTOPENGL_TEXTUREUTIL_H
