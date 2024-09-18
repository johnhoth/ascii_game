cmake_minimum_required(VERSION 3.30)

project(ascii_game VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SDL2_PATH "${CMAKE_SOURCE_DIR}/external/SDL2")
include_directories(${SDL2_PATH}/include)

find_package(GLM REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})

# Включаем поддержку тестирования
enable_testing()

# Добавляем поддиректории
add_subdirectory(src)
add_subdirectory(tests)
