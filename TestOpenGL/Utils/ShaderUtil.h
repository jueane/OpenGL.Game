#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class ShaderUtil {
public:
    unsigned int ID;

    ShaderUtil();

    ShaderUtil(const GLchar *vertexPath, const GLchar *fragmentPath);

    void Use();

    void setBool(const string &name, bool value) const;

    void setInt(const string &name, int value) const;

    void setFloat(const string &name, float value) const;

    void setVec3(const string &name, float a, float b, float c);

    void setVec3(const string &name, glm::vec3 vec3);

    void setVec4(const string &name, glm::vec4 vec4);

    void setMatrix(const string &name, glm::mat4 mat4);
};

#endif
