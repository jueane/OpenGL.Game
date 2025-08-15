@echo off
chcp 65001 > nul

if not exist "CmakeBuild" (
    mkdir CmakeBuild
)
cd CmakeBuild


:: 检查 CMakeCache.txt 是否存在，如果不存在则先运行 cmake 配置
if not exist "CMakeCache.txt" (
    echo [INFO] CMakeCache.txt not found. Running cmake configuration...
    cmake ..
    if %ERRORLEVEL% neq 0 (
        echo [ERROR] CMake configuration failed. Check your CMakeLists.txt.
        exit /b %ERRORLEVEL%
    )
)


@REM cmake --build . --config release
cmake --build . --config Debug
