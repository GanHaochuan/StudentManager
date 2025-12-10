cmake_minimum_required(VERSION 3.10)

project(StudentManager VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# 核心库
add_library(core
    src/Student.cpp
)

target_include_directories(core PUBLIC include)

# 主程序
add_executable(app
    src/main.cpp
    src/use.cpp
)

target_link_libraries(app core)