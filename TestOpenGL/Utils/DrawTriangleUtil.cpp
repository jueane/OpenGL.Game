//
// Created by Administrator on 2024/5/26.
//

#include "DrawTriangleUtil.h"
#include "glad/glad.h"

DrawTriangleUtil::DrawTriangleUtil(int lenOfVertex, float vertices[], int verticesSize, unsigned int indices[],
                                   int indicesSize) {

    this->lenOfVertex = lenOfVertex;
    this->vertices = vertices;
    this->verticesSize = verticesSize;
    this->indices = indices;
    this->indicesSize = indicesSize;

    this->Draw();
}

DrawTriangleUtil::~DrawTriangleUtil() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void DrawTriangleUtil::Draw() {

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

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
}
