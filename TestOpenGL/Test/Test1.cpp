//
// Created by Administrator on 2023/12/18.
//

#include "Test1.h"
//#include "../Utils/TextureUtil.h"
//#include "../Utils/ShaderUtil.h"
//#include "../glad.c"

namespace fs = std::filesystem;
using namespace std;

void Test2()
{

    try
    {
        // 获取当前工作目录
        fs::path currentPath = fs::current_path();

        std::cout << "当前所在目录: " << currentPath << std::endl;

        // 列出当前目录下的所有文件和子目录
        std::cout << "目录内容:\n";
        for (const auto &entry: fs::directory_iterator(currentPath))
        {
            std::cout << entry.path() << std::endl;
        }
    } catch (const std::exception &e)
    {
        std::cerr << "发生异常: " << e.what() << std::endl;
    }
}

void Test3()
{
//    auto tex = new TextureUtil("resources/textures/container.jpg");
//    unsigned int texture;
//    glGenTextures(1, &texture);

}

void Test1::Test()
{
//    Test2();
    Test3();
}
