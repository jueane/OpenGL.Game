//
// Created by Administrator on 2024/5/26.
//

#ifndef TESTOPENGL_SLN_MESH_H
#define TESTOPENGL_SLN_MESH_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <vector>
#include "../ShaderUtil.h"

using namespace std;

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    string type;
    string path;
};


class Mesh {
public:
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;

    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);

    void Draw(ShaderUtil shaderUtil);

private:
    unsigned int VAO, VBO, EBO;

    void setupMesh();
};


#endif //TESTOPENGL_SLN_MESH_H
