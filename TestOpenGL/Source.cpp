#include "Feature/DrawTriangle.h"
#include "Feature/DrawTexture.h"
#include "Feature/TestMatrix.h"
#include "Test/Test1.h"

int main() {
    auto err = glfwInit();
    cout << "init result " << err << endl;

    auto test1 = new Test1();
    test1->Test();

//    auto drawTriangle = new DrawTriangle();
//    drawTriangle->Draw();

    auto drawTex = new DrawTexture();
    drawTex->Draw();

//    auto testMatrix = new TestMatrix();
//    testMatrix->Test1();


    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    cout << "Support vertex attributes count: " << nrAttributes << endl;

    return 0;
}