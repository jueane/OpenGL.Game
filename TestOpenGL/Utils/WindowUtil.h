//
// Created by Administrator on 2024/5/28.
//

#ifndef TESTOPENGL_SLN_WINDOWUTIL_H
#define TESTOPENGL_SLN_WINDOWUTIL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class WindowUtil {
public:

    static int width;
    static int height;

    static GLFWwindow *createWindowUtil(int width, int height);

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
};


#endif //TESTOPENGL_SLN_WINDOWUTIL_H
