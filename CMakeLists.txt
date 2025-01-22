cmake_minimum_required(VERSION 3.10)
project(CPMULTI)

set(OpenCV_DIR "C:/opencv/build/x64/mingw64")

find_package(OpenCV REQUIRED)

if(OpenCV_FOUND)
    message(STATUS "OpenCV found: ${OpenCV_VERSION}")
    message(STATUS "OpenCV include directories: ${OpenCV_INCLUDE_DIRS}")
    message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")
else()
    message(FATAL_ERROR "OpenCV not found!")
endif()

include_directories(C:/opencv/build/include)

add_executable(${PROJECT_NAME} Main.cpp
                src/TerminalDisplay.cpp
                src/InputValidator.cpp
                src/GaussianBlurProcessor.cpp
                src/CannyEdgeDetection.cpp
)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
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