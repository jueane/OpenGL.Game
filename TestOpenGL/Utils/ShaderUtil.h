#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class ShaderUtil
{
public:
    unsigned int ID;

    ShaderUtil();

    ShaderUtil(const GLchar *vertexPath, const GLchar *fragmentPath);

    void Use();

    void setBool(const string &name, bool value) const;

    void setInt(const string &name, int value) const;

    void setFloat(const string &name, float value) const;
};

#endif
