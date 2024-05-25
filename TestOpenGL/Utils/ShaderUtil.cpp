#include "ShaderUtil.h"

ShaderUtil::ShaderUtil()
{
    cout << "hi...." << endl;
}

ShaderUtil::ShaderUtil(const GLchar *vertexPath, const GLchar *fragmentPath)
{
    cout << "Compile shader ..." << endl;
    string vertexCode;
    string fragCode;
    ifstream vShaderFile;
    ifstream fShaderFile;
    cout << "vertex path: " << vertexPath;
    cout << "fragment path: " << fragmentPath;
    vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    try
    {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        stringstream vStream;
        stringstream fStream;
        vStream << vShaderFile.rdbuf();
        fStream << fShaderFile.rdbuf();
        vShaderFile.close();
        fShaderFile.close();
        vertexCode = vStream.str();
        fragCode = fStream.str();
    }
    catch (ifstream::failure e)
    // catch (exception e)
    {
        cout << "Read file failed ," << e.what() << endl;
        return;
    }
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragCode.c_str();

    unsigned int vertex;
    unsigned int fragment;

    int success;
    char infoLog[512];
    // auto LOGLEN = sizeof(infoLog) / sizeof(char);

    // 顶点着色器

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
    // 打印编译错误
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        cout << "ShaderUtil compile error in vertex. " << infoLog << endl;
    }

    // 片段着急器
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
    // 打印编译错误
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        cout << "ShaderUtil compile error in fragment. " << infoLog << endl;
    }

    // 创建着色器程序
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    // 链接
    glLinkProgram(ID);
    // 打印链接错误
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ID, 512, nullptr, infoLog);
        cout << "ShaderUtil link error in. " << infoLog << endl;
    }
    cout << "ShaderUtil compile success." << endl;

    // 删除着色器
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void ShaderUtil::Use()
{
//    cout << "use shader " << ID << endl;
    glUseProgram(ID);
}

void ShaderUtil::setBool(const string &name, bool value) const
{
    glUniform1i(glad_glGetUniformLocation(ID, name.c_str()), (int) value);
}

void ShaderUtil::setInt(const string &name, int value) const
{
    glUniform1i(glad_glGetUniformLocation(ID, name.c_str()), value);
}

void ShaderUtil::setFloat(const string &name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}