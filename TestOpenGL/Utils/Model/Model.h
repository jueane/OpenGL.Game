//
// Created by Administrator on 2024/5/26.
//

#ifndef TESTOPENGL_SLN_MODEL_H
#define TESTOPENGL_SLN_MODEL_H

#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Mesh.h"

using namespace std;

class Model {
    vector<Texture> textures_loaded;


public:
    Model(char *path) {
        loadModel(path);
    }

    void Draw(ShaderUtil shaderUtil);

private:
    vector<Mesh> meshes;
    string directory;

    void loadModel(string path);

    void processNode(aiNode *node, const aiScene *scene);

    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

    vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};


#endif //TESTOPENGL_SLN_MODEL_H
