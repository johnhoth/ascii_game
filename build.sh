#!/bin/bash

# Define the build directory
BUILD_DIR="build"

# Remove the build directory if it exists
if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
    echo "Removed existing build directory."
fi

# Create the build directory
mkdir "$BUILD_DIR"
echo "Created build directory."

# Navigate to the build directory
cd "$BUILD_DIR" || exit

# Run CMake and build
cmake ..
cmake --build .
echo "Build completed."
