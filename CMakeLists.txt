cmake_minimum_required(VERSION 3.10)
project(CPMULTI)

# Specify the path to OpenCV
set(OpenCV_DIR C:/opencv/build)
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add the executable
add_executable(${PROJECT_NAME} 
    Main.cpp
    src/GaussianBlurProcessor.cpp
)

# Link OpenCV libraries
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
