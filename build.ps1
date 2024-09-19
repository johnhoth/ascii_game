# Define the build directory
$BUILD_DIR = "build"

# Remove the build directory if it exists
if (Test-Path $BUILD_DIR) {
    Remove-Item -Recurse -Force $BUILD_DIR
    Write-Host "Removed existing build directory."
}

# Create the build directory
New-Item -ItemType Directory -Name $BUILD_DIR
Write-Host "Created build directory."

# Navigate to the build directory
Set-Location $BUILD_DIR

# Run CMake and build
cmake ..
cmake --build .
Write-Host "Build completed."
