@REM 编译命令

g++ -g TestOpenGL\Source.cpp TestOpenGL\Test\*.cpp TestOpenGL\Feature\*.cpp TestOpenGL\Utils\*.cpp -I Ref\Include -LRef\Libs -lglfw3dll -o build\app
