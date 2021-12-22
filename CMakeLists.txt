cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
project(TestOpenGL)
add_executable(TestOpenGL TestOpenGL/Source.cpp TestOpenGL/Shader.h TestOpenGL/Shader.cpp)

target_include_directories(TestOpenGL PUBLIC ${PROJECT_SOURCE_DIR}/Ref/Include/)

# set(source
# TestOpenGL/Shader.h
# )



# target_link_libraries(TestOpenGL PUBLIC ${PROJECT_SOURCE_DIR}/Ref/Libs/)

# target_link_libraries(TestOpenGL PRIVATE D:/cpp/glfw/build/src/Debug/glfw3.lib)
#target_link_libraries(TestOpenGL PRIVATE ${PROJECT_SOURCE_DIR}/Ref/Libs/glfw3_x64/glfw3.lib)
target_link_libraries(TestOpenGL PRIVATE ${PROJECT_SOURCE_DIR}/Ref/Libs/glfw3.lib)

# set_property(TARGET TestOpenGL PROPERTY
#   MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
