cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
project(TestOpenGL)

add_executable(TestOpenGL
        TestOpenGL/Test/Test1.cpp
        TestOpenGL/Source.cpp
        TestOpenGL/Utils/ShaderUtil.cpp
        TestOpenGL/Feature/DrawTriangle.cpp
        TestOpenGL/Utils/TextureUtil.cpp
        TestOpenGL/std_image_impl.h TestOpenGL/Feature/DrawTexture.cpp TestOpenGL/Feature/DrawTexture.h TestOpenGL/Feature/ImageLoader.cpp TestOpenGL/Feature/ImageLoader.h TestOpenGL/Feature/TestMatrix.cpp TestOpenGL/Feature/TestMatrix.h)

target_include_directories(TestOpenGL PUBLIC ${PROJECT_SOURCE_DIR}/Ref/Include/)

#target_link_libraries(TestOpenGL PRIVATE ${PROJECT_SOURCE_DIR}/Ref/Libs/glfw3.lib)
target_link_libraries(TestOpenGL PRIVATE ${PROJECT_SOURCE_DIR}/Ref/Libs/libglfw3.a)

file(COPY ${CMAKE_SOURCE_DIR}/TestOpenGL/Shader DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/TestOpenGL/resources DESTINATION ${CMAKE_BINARY_DIR})
