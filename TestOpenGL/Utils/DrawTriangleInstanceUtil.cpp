//
// Created by Administrator on 2024/5/29.
//

#include "DrawTriangleInstanceUtil.h"
#include "glad/glad.h"

DrawTriangleInstanceUtil::DrawTriangleInstanceUtil(int lenOfVertex, float vertices[], int verticesSize,
                                                   unsigned int indices[],
                                                   int indicesSize) {

    this->lenOfVertex = lenOfVertex;
    this->vertices = vertices;
    this->verticesSize = verticesSize;
    this->indices = indices;
    this->indicesSize = indicesSize;

    this->Init();
}

void DrawTriangleInstanceUtil::Init() {

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, lenOfVertex * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, lenOfVertex * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    if (lenOfVertex >= 8) {
        // texture coord attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, lenOfVertex * sizeof(float), (void *) (6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }
    if (lenOfVertex >= 11) {
        // 高光贴图
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, lenOfVertex * sizeof(float), (void *) (8 * sizeof(float)));
        glEnableVertexAttribArray(3);
    }
}

void DrawTriangleInstanceUtil::Draw() {
    glBindVertexArray(VAO);
    glDrawElementsInstanced(GL_TRIANGLES, this->verticesSize, GL_UNSIGNED_INT, 0, drawNum);
}

DrawTriangleInstanceUtil::~DrawTriangleInstanceUtil() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void DrawTriangleInstanceUtil::setPosArray(glm::vec3 *posArray, int num) {

    drawNum=num;
    unsigned int instanceVBO;
    glGenBuffers(1, &instanceVBO);
    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * num, posArray, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // 实例化位置数据
    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(4);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glVertexAttribDivisor(4, 1);

}
