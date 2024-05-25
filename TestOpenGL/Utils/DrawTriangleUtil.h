//
// Created by Administrator on 2024/5/26.
//

#ifndef TESTOPENGL_SLN_DRAWTRIANGLEUTIL_H
#define TESTOPENGL_SLN_DRAWTRIANGLEUTIL_H


class DrawTriangleUtil {
public:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    DrawTriangleUtil(int lenOfVertex, float vertices[], int verticesSize, unsigned int indices[], int indicesSize);

    ~DrawTriangleUtil();
};


#endif //TESTOPENGL_SLN_DRAWTRIANGLEUTIL_H
