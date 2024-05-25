//
// Created by Administrator on 2024/5/25.
//

#include "TestMatrix.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#define NAMEOF(x) #x

using namespace std;

void TestMatrix::Test1() {
    cout << NAMEOF(TestMatrix) << endl;

    glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));

    vec = trans * vec;

    cout << vec.x << endl;
    cout << vec.y << endl;
    cout << vec.z << endl;
}

void TestMatrix::Test2() {
    glm::mat4 trans = glm::mat4(1.0f);



}
