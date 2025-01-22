cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(CPMULTI)

# Chemin vers OpenCV
set(OpenCV_DIR C:/opencv/build)

# Ajouter les headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Rechercher OpenCV
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} 
    Main.cpp
    src/TerminalDisplay.cpp
    src/InputValidator.cpp
    src/CannyEdgeDetection.cpp
    )

# Lier les bibliothèques OpenCV
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})