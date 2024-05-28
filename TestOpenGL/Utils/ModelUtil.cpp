//
// Created by Administrator on 2024/5/26.
//

#include "ModelUtil.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>
#include "Model/Model.h"

ModelUtil::ModelUtil() {
//    Assimp::Importer importer;
//    const aiScene *scene = importer.ReadFile("resources\\objects\\rock\\rock.obj", aiProcess_Triangulate | aiProcess_FlipUVs);
//
//    std::cout << "ok" << std::endl;
//
//    if (!scene) {
//        std::cerr << "Failed to load model file!" << std::endl;
//        return;
//    }
//
//    // 输出模型信息
//    std::cout << "Model information:" << std::endl;
//    std::cout << "Number of meshes: " << scene->mNumMeshes << std::endl;
//
//    // 遍历模型的所有网格
//    for (unsigned int i = 0; i < scene->mNumMeshes; ++i) {
//        const aiMesh *mesh = scene->mMeshes[i];
//        std::cout << "Mesh " << i << ":" << std::endl;
//        std::cout << "  Number of vertices: " << mesh->mNumVertices << std::endl;
//        std::cout << "  Number of faces: " << mesh->mNumFaces << std::endl;
//        // 可以继续输出其他属性，如顶点坐标、法线、纹理坐标等
//    }



}
