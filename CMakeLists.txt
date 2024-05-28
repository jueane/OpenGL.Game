cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
project(TestOpenGL)

add_executable(TestOpenGL
        TestOpenGL/Test/Test1.cpp
        TestOpenGL/Source.cpp
        TestOpenGL/Utils/ShaderUtil.cpp
        TestOpenGL/Utils/TextureUtil.cpp
        TestOpenGL/std_image_impl.h
        TestOpenGL/Feature/DrawTexture.cpp
        TestOpenGL/Feature/ImageLoader.cpp
        TestOpenGL/Feature/ImageLoader.h
        TestOpenGL/Feature/TestMatrix.cpp
        TestOpenGL/Feature/TestMatrix.h
        TestOpenGL/Feature/DrawCube.cpp
        TestOpenGL/Feature/DrawCube.h
        TestOpenGL/Feature/Camera.h
        TestOpenGL/Feature/DrawCubeColor.cpp
        TestOpenGL/Feature/DrawCubeColor.h
        TestOpenGL/Feature/TestLoadModel.cpp
        TestOpenGL/Feature/TestLoadModel.h
        TestOpenGL/Feature/CameraTemp.h
        TestOpenGL/Feature/CameraTemp.cpp
        TestOpenGL/Utils/DrawTriangleUtil.cpp
        TestOpenGL/Utils/DrawTriangleUtil.h
        TestOpenGL/Feature/DrawQuadrilateral.cpp
        TestOpenGL/Feature/DrawQuadrilateral.h
        TestOpenGL/Utils/ModelUtil.cpp
        TestOpenGL/Utils/ModelUtil.h
        TestOpenGL/Utils/Model/Mesh.cpp
        TestOpenGL/Utils/Model/Mesh.h
        TestOpenGL/Utils/Model/Model.cpp
        TestOpenGL/Utils/Model/Model.h)

target_include_directories(TestOpenGL PUBLIC ${PROJECT_SOURCE_DIR}/Ref/Include/)

target_link_libraries(TestOpenGL PRIVATE ${PROJECT_SOURCE_DIR}/Ref/Libs/libglfw3.a)
target_link_libraries(TestOpenGL PRIVATE ${PROJECT_SOURCE_DIR}/Ref/Libs/libassimp-5d.dll)


file(COPY ${CMAKE_SOURCE_DIR}/TestOpenGL/Shader DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/TestOpenGL/resources DESTINATION ${CMAKE_BINARY_DIR})

# 复制Assimp DLL文件到生成的可执行文件目录
file(COPY ${CMAKE_SOURCE_DIR}/Ref/Libs/libassimp-5d.dll DESTINATION ${CMAKE_BINARY_DIR})