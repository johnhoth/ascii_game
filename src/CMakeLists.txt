# src/CMakeLists.txt

# Include directories for engine and utils
include_directories(${CMAKE_SOURCE_DIR}/include/engine)
include_directories(${CMAKE_SOURCE_DIR}/include/utils)

include_directories(${CMAKE_SOURCE_DIR}/src)

# Add the main executable
add_executable(${PROJECT_NAME}
    main.cpp
)
