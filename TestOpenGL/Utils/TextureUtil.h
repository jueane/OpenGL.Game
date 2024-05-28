//
// Created by Administrator on 2021/12/25.
//

#ifndef TESTOPENGL_TEXTUREUTIL_H
#define TESTOPENGL_TEXTUREUTIL_H

#include <string>
#include <iostream>

class TextureUtil {
public:
    unsigned int texture;

    int width, height, nrChannels;

    unsigned char *data;

    int texture_index;

    TextureUtil(const char *path, bool hasAlpha);

    void active(int index);

    ~TextureUtil();
};

#endif //TESTOPENGL_TEXTUREUTIL_H
