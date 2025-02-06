cmake_minimum_required(VERSION 3.10)
project(CPMULTI)

set(OpenCV_DIR "C:/opencv/build/x64/mingw64")


find_package(OpenCV REQUIRED)

find_package(Python3 REQUIRED COMPONENTS Development NumPy)
if (NOT Python3_FOUND)
    message(FATAL_ERROR "Python3 not found!")
    set(Python3_EXECUTABLE "C:\\Users\\Vanny Laure Lamorte\\AppData\\Local\\Programs\\Python\\Python312\\python.exe")
    find_package(Python3 COMPONENTS Interpreter NumPy REQUIRED)
else()
    message(STATUS "Python3 found: ${Python3_VERSION}")
    message(STATUS "Python3 include directories: ${Python3_INCLUDE_DIRS}")
    message(STATUS "Python3 libraries: ${Python3_LIBRARIES}")
    message(STATUS "Python3 NumPy include directories: ${Python3_NumPy_INCLUDE_DIRS}")
endif()

if(OpenCV_FOUND)
    message(STATUS "OpenCV found: ${OpenCV_VERSION}")
    message(STATUS "OpenCV include directories: ${OpenCV_INCLUDE_DIRS}")
    message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")
else()
    message(FATAL_ERROR "OpenCV not found!")
endif()

include_directories(C:/opencv/build/include)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(
    ${Python3_INCLUDE_DIRS}
    ${Python3_NumPy_INCLUDE_DIRS}
)

file(GLOB SRC_FILES src/core/*.cpp src/io/*.cpp src/ui/*.cpp src/main.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES}
                Main.cpp)


# # Include OpenCV headers
# include_directories(
#     ${OpenCV_INCLUDE_DIRS}
#     ${Python3_INCLUDE_DIRS}
#     ${Python3_NumPy_INCLUDE_DIRS})

# # Add the executable
# add_executable(${PROJECT_NAME} 

# Main.cpp
# src/TerminalDisplay.cpp
# src/InputValidator.cpp
# src/GaussianBlurProcessor.cpp
# src/CannyEdgeDetection.cpp
# )

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
# Todo use the following command line to build the project :
#into C:\Users\tslem\Desktop\Laplateforme\bachelore2\depot\Cpp\projetGroupe\Mutexisation\CPMULTI\build
# cmake -G "MinGW Makefiles" -S . -B build
# "_commentaire": "cmake --build preset release",
# "_commentaire":  "cmake --build --preset default",
# cmake --build .

# hardcore link below
# target_link_libraries(main
#     ${OpenCV_LIBS}
#     C:/opencv/build/x64/mingw64/lib/libopencv_calib3d4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_core4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_dnn4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_features2d4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_flann4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_gapi4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_highgui4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_imgcodecs4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_imgproc4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_ml4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_objdetect4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_photo4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_ts4110.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_videoio4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_stitching4110.dll.a
#     C:/opencv/build/x64/mingw64/lib/libopencv_video4110.dll.a
# )


target_link_libraries(${PROJECT_NAME} ${Python3_LIBRARIES})
