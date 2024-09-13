# src/CMakeLists.txt

# Create a library from your project source files
add_library(${PROJECT_NAME}_lib STATIC
    engine/Renderer.cpp
    engine/Input.cpp
    engine/Scene.cpp
    utils/Math.cpp
    utils/Vector3.cpp
    # Add other source files here
)

# Add the main executable
add_executable(${PROJECT_NAME}
    main.cpp
)

# Link the main executable with your project library
target_link_libraries(${PROJECT_NAME}
    ${PROJECT_NAME}_lib
)

# Include directories for the main executable and library
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)
target_include_directories(${PROJECT_NAME}_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)
