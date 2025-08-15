//
// Created by Administrator on 2024/5/28.
//

#include "WindowUtil.h"
#include <iostream>
#include "../Feature/CameraTemp.h"
#include <glad/glad.h>

using namespace std;

int WindowUtil::width = 0;
int WindowUtil::height = 0;

GLFWwindow *WindowUtil::createWindowUtil(int width, int height)
{

    WindowUtil::width = width;
    WindowUtil::height = height;

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto console = GetConsoleWindow();
    RECT rect;
    GetWindowRect(console, &rect);
    auto consoleX = rect.left;
    auto consoleY = rect.top;
    cout << "控制台窗口坐标：" << consoleX << ", " << consoleY << endl;
    if (consoleX == 0 && consoleY == 0)
    {
        consoleX = 900;
        consoleY = 300;
    }
    else
    {
        consoleX += 800;
        // consoleY = 600;
    }

    GLFWwindow *window = glfwCreateWindow(width, height, "My Game", NULL, NULL);
    if (window == nullptr)
    {
        cout << "create gl window failed" << endl;
        glfwTerminate();
        return nullptr;
    }

    cout << "Window created" << endl;
    glfwSetFramebufferSizeCallback(window, WindowUtil::framebuffer_size_callback);
    glfwSetWindowPos(window, consoleX, consoleY);
    glfwMakeContextCurrent(window);

    glfwSetCursorPosCallback(window, CameraTemp::mouse_callback);
    glfwSetScrollCallback(window, CameraTemp::scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "failed init glad" << endl;
        return nullptr;
    }

    return window;
}

void WindowUtil::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    cout << "reset window size" << endl;
    glViewport(0, 0, width, height);
}
