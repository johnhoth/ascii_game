cmake_minimum_required(VERSION 3.30)

# Set default VCPKG path based on the current username
if(WIN32)
    set(DEFAULT_VCPKG_PATH "C:/Users/$ENV{USERNAME}/vcpkg")
else()
    set(DEFAULT_VCPKG_PATH "/home/$ENV{USER}/vcpkg")
endif()

# Allow users to override the default VCPKG path by setting the VCPKG_ROOT environment variable
if(DEFINED ENV{VCPKG_ROOT})
    set(VCPKG_PATH $ENV{VCPKG_ROOT})
else()
    set(VCPKG_PATH ${DEFAULT_VCPKG_PATH})
endif()

# Set the toolchain file for vcpkg
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Print a message to show which vcpkg path is being used
message(STATUS "Using vcpkg from: ${VCPKG_PATH}")

# Set the project name
project(ascii_game)


# Include directories for engine and utils
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/engine)
include_directories(${CMAKE_SOURCE_DIR}/include/utils)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the paths for source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Add the executable
add_executable(ascii_game ${SOURCES})

# Set paths for SDL2
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(ascii_game
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

# Set paths for SDL_ttf
find_package(SDL2_ttf CONFIG REQUIRED)
target_link_libraries(ascii_game PRIVATE SDL2::SDL2 SDL2_ttf::SDL2_ttf)

# Set paths for GLM
find_package(glm CONFIG REQUIRED)
target_link_libraries(ascii_game PRIVATE glm::glm)