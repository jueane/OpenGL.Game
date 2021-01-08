# 编译命令

# g++ -g TestOpenGL/Source.cpp -I Ref/Include -L/usr/local/lib -l:libglfw3.a -o build/app -ldl -lpthread

g++ -g TestOpenGL/Source.cpp -I Ref/Include -L/Ref/Libs -l:libglfw3.a -o build/app -ldl -lpthread
