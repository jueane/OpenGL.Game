#include "Feature/DrawQuadrilateral.h"
#include "Feature/DrawTexture.h"
#include "Feature/TestMatrix.h"
#include "Feature/DrawCube.h"
#include "Feature/DrawCubeColor.h"
#include "Feature/TestLoadModel.h"
#include "Feature/DrawCubeInstance.h"
#include "Test/Test1.h"
#include "Utils/ModelUtil.h"

int main() {

#ifdef _WIN32
    // 设置控制台输出为 UTF-8 编码
    SetConsoleOutputCP(CP_UTF8);
    // 可选：设置控制台输入也为 UTF-8（如果需要输入）
    SetConsoleCP(CP_UTF8);
#endif

//    (new Test1())->Test();

    new ModelUtil();


//    (new DrawQuadrilateral())->Draw();
//    (new DrawTexture())->Draw();
//    (new DrawCube())->Draw();
//    (new DrawCubeColor())->Draw();
//    (new TestLoadModel())->Draw();
    (new DrawCubeInstance)->draw();


//    (new TestMatrix())->Test1();
    return 0;
}