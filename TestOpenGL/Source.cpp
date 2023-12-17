#include "Feature/DrawTriangle.h"
#include "Test/Test1.h"


int main()
{
    auto test1 = new Test1();
    test1->Test();

    auto drawTriangle = new DrawTriangle();
    drawTriangle->Draw();

    return 0;
}