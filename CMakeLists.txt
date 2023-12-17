cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
project(TestOpenGL)

add_executable(TestOpenGL
        TestOpenGL/Test/Test1.cpp
        TestOpenGL/Source.cpp
        TestOpenGL/Utils/ShaderUtil.cpp
        TestOpenGL/Feature/DrawTriangle.cpp
        TestOpenGL/Utils/TextureUtil.cpp
        )

target_include_directories(TestOpenGL PUBLIC ${PROJECT_SOURCE_DIR}/Ref/Include/)

#target_link_libraries(TestOpenGL PRIVATE ${PROJECT_SOURCE_DIR}/Ref/Libs/glfw3.lib)
target_link_libraries(TestOpenGL PRIVATE ${PROJECT_SOURCE_DIR}/Ref/Libs/libglfw3.a)

