//
// Created by Administrator on 2024/5/29.
//

#ifndef TESTOPENGL_SLN_DRAWTRIANGLEINSTANCEUTIL_H
#define TESTOPENGL_SLN_DRAWTRIANGLEINSTANCEUTIL_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class DrawTriangleInstanceUtil {
public:

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    int lenOfVertex;
    float *vertices;
    int verticesSize;
    unsigned int *indices;
    int indicesSize;

    int drawNum;

    DrawTriangleInstanceUtil(int lenOfVertex, float vertices[], int verticesSize, unsigned int indices[],
                             int indicesSize);

    void Init();

    void setPosArray(glm::mat4 *matArray, int num);

    void Draw();

    ~DrawTriangleInstanceUtil();

};


#endif //TESTOPENGL_SLN_DRAWTRIANGLEINSTANCEUTIL_H
