# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lucas\Desktop\2025\CPMULTI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lucas\Desktop\2025\CPMULTI\build

# Include any dependencies generated for this target.
include CMakeFiles/CPMULTI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CPMULTI.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CPMULTI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPMULTI.dir/flags.make

CMakeFiles/CPMULTI.dir/Main.cpp.obj: CMakeFiles/CPMULTI.dir/flags.make
CMakeFiles/CPMULTI.dir/Main.cpp.obj: CMakeFiles/CPMULTI.dir/includes_CXX.rsp
CMakeFiles/CPMULTI.dir/Main.cpp.obj: C:/Users/lucas/Desktop/2025/CPMULTI/Main.cpp
CMakeFiles/CPMULTI.dir/Main.cpp.obj: CMakeFiles/CPMULTI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\2025\CPMULTI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPMULTI.dir/Main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPMULTI.dir/Main.cpp.obj -MF CMakeFiles\CPMULTI.dir\Main.cpp.obj.d -o CMakeFiles\CPMULTI.dir\Main.cpp.obj -c C:\Users\lucas\Desktop\2025\CPMULTI\Main.cpp

CMakeFiles/CPMULTI.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPMULTI.dir/Main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\2025\CPMULTI\Main.cpp > CMakeFiles\CPMULTI.dir\Main.cpp.i

CMakeFiles/CPMULTI.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPMULTI.dir/Main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\2025\CPMULTI\Main.cpp -o CMakeFiles\CPMULTI.dir\Main.cpp.s

CMakeFiles/CPMULTI.dir/src/TerminalDisplay.cpp.obj: CMakeFiles/CPMULTI.dir/flags.make
CMakeFiles/CPMULTI.dir/src/TerminalDisplay.cpp.obj: CMakeFiles/CPMULTI.dir/includes_CXX.rsp
CMakeFiles/CPMULTI.dir/src/TerminalDisplay.cpp.obj: C:/Users/lucas/Desktop/2025/CPMULTI/src/TerminalDisplay.cpp
CMakeFiles/CPMULTI.dir/src/TerminalDisplay.cpp.obj: CMakeFiles/CPMULTI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\2025\CPMULTI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CPMULTI.dir/src/TerminalDisplay.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPMULTI.dir/src/TerminalDisplay.cpp.obj -MF CMakeFiles\CPMULTI.dir\src\TerminalDisplay.cpp.obj.d -o CMakeFiles\CPMULTI.dir\src\TerminalDisplay.cpp.obj -c C:\Users\lucas\Desktop\2025\CPMULTI\src\TerminalDisplay.cpp

CMakeFiles/CPMULTI.dir/src/TerminalDisplay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPMULTI.dir/src/TerminalDisplay.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\2025\CPMULTI\src\TerminalDisplay.cpp > CMakeFiles\CPMULTI.dir\src\TerminalDisplay.cpp.i

CMakeFiles/CPMULTI.dir/src/TerminalDisplay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPMULTI.dir/src/TerminalDisplay.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\2025\CPMULTI\src\TerminalDisplay.cpp -o CMakeFiles\CPMULTI.dir\src\TerminalDisplay.cpp.s

CMakeFiles/CPMULTI.dir/src/InputValidator.cpp.obj: CMakeFiles/CPMULTI.dir/flags.make
CMakeFiles/CPMULTI.dir/src/InputValidator.cpp.obj: CMakeFiles/CPMULTI.dir/includes_CXX.rsp
CMakeFiles/CPMULTI.dir/src/InputValidator.cpp.obj: C:/Users/lucas/Desktop/2025/CPMULTI/src/InputValidator.cpp
CMakeFiles/CPMULTI.dir/src/InputValidator.cpp.obj: CMakeFiles/CPMULTI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\2025\CPMULTI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CPMULTI.dir/src/InputValidator.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPMULTI.dir/src/InputValidator.cpp.obj -MF CMakeFiles\CPMULTI.dir\src\InputValidator.cpp.obj.d -o CMakeFiles\CPMULTI.dir\src\InputValidator.cpp.obj -c C:\Users\lucas\Desktop\2025\CPMULTI\src\InputValidator.cpp

CMakeFiles/CPMULTI.dir/src/InputValidator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPMULTI.dir/src/InputValidator.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\2025\CPMULTI\src\InputValidator.cpp > CMakeFiles\CPMULTI.dir\src\InputValidator.cpp.i

CMakeFiles/CPMULTI.dir/src/InputValidator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPMULTI.dir/src/InputValidator.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\2025\CPMULTI\src\InputValidator.cpp -o CMakeFiles\CPMULTI.dir\src\InputValidator.cpp.s

CMakeFiles/CPMULTI.dir/src/GaussianBlurProcessor.cpp.obj: CMakeFiles/CPMULTI.dir/flags.make
CMakeFiles/CPMULTI.dir/src/GaussianBlurProcessor.cpp.obj: CMakeFiles/CPMULTI.dir/includes_CXX.rsp
CMakeFiles/CPMULTI.dir/src/GaussianBlurProcessor.cpp.obj: C:/Users/lucas/Desktop/2025/CPMULTI/src/GaussianBlurProcessor.cpp
CMakeFiles/CPMULTI.dir/src/GaussianBlurProcessor.cpp.obj: CMakeFiles/CPMULTI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\2025\CPMULTI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CPMULTI.dir/src/GaussianBlurProcessor.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPMULTI.dir/src/GaussianBlurProcessor.cpp.obj -MF CMakeFiles\CPMULTI.dir\src\GaussianBlurProcessor.cpp.obj.d -o CMakeFiles\CPMULTI.dir\src\GaussianBlurProcessor.cpp.obj -c C:\Users\lucas\Desktop\2025\CPMULTI\src\GaussianBlurProcessor.cpp

CMakeFiles/CPMULTI.dir/src/GaussianBlurProcessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPMULTI.dir/src/GaussianBlurProcessor.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\2025\CPMULTI\src\GaussianBlurProcessor.cpp > CMakeFiles\CPMULTI.dir\src\GaussianBlurProcessor.cpp.i

CMakeFiles/CPMULTI.dir/src/GaussianBlurProcessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPMULTI.dir/src/GaussianBlurProcessor.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\2025\CPMULTI\src\GaussianBlurProcessor.cpp -o CMakeFiles\CPMULTI.dir\src\GaussianBlurProcessor.cpp.s

CMakeFiles/CPMULTI.dir/src/CannyEdgeDetection.cpp.obj: CMakeFiles/CPMULTI.dir/flags.make
CMakeFiles/CPMULTI.dir/src/CannyEdgeDetection.cpp.obj: CMakeFiles/CPMULTI.dir/includes_CXX.rsp
CMakeFiles/CPMULTI.dir/src/CannyEdgeDetection.cpp.obj: C:/Users/lucas/Desktop/2025/CPMULTI/src/CannyEdgeDetection.cpp
CMakeFiles/CPMULTI.dir/src/CannyEdgeDetection.cpp.obj: CMakeFiles/CPMULTI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\lucas\Desktop\2025\CPMULTI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CPMULTI.dir/src/CannyEdgeDetection.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPMULTI.dir/src/CannyEdgeDetection.cpp.obj -MF CMakeFiles\CPMULTI.dir\src\CannyEdgeDetection.cpp.obj.d -o CMakeFiles\CPMULTI.dir\src\CannyEdgeDetection.cpp.obj -c C:\Users\lucas\Desktop\2025\CPMULTI\src\CannyEdgeDetection.cpp

CMakeFiles/CPMULTI.dir/src/CannyEdgeDetection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPMULTI.dir/src/CannyEdgeDetection.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lucas\Desktop\2025\CPMULTI\src\CannyEdgeDetection.cpp > CMakeFiles\CPMULTI.dir\src\CannyEdgeDetection.cpp.i

CMakeFiles/CPMULTI.dir/src/CannyEdgeDetection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPMULTI.dir/src/CannyEdgeDetection.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lucas\Desktop\2025\CPMULTI\src\CannyEdgeDetection.cpp -o CMakeFiles\CPMULTI.dir\src\CannyEdgeDetection.cpp.s

# Object files for target CPMULTI
CPMULTI_OBJECTS = \
"CMakeFiles/CPMULTI.dir/Main.cpp.obj" \
"CMakeFiles/CPMULTI.dir/src/TerminalDisplay.cpp.obj" \
"CMakeFiles/CPMULTI.dir/src/InputValidator.cpp.obj" \
"CMakeFiles/CPMULTI.dir/src/GaussianBlurProcessor.cpp.obj" \
"CMakeFiles/CPMULTI.dir/src/CannyEdgeDetection.cpp.obj"

# External object files for target CPMULTI
CPMULTI_EXTERNAL_OBJECTS =

CPMULTI.exe: CMakeFiles/CPMULTI.dir/Main.cpp.obj
CPMULTI.exe: CMakeFiles/CPMULTI.dir/src/TerminalDisplay.cpp.obj
CPMULTI.exe: CMakeFiles/CPMULTI.dir/src/InputValidator.cpp.obj
CPMULTI.exe: CMakeFiles/CPMULTI.dir/src/GaussianBlurProcessor.cpp.obj
CPMULTI.exe: CMakeFiles/CPMULTI.dir/src/CannyEdgeDetection.cpp.obj
CPMULTI.exe: CMakeFiles/CPMULTI.dir/build.make
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_gapi455.dll.a
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_highgui455.dll.a
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_ml455.dll.a
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_objdetect455.dll.a
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_photo455.dll.a
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_stitching455.dll.a
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_video455.dll.a
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_videoio455.dll.a
CPMULTI.exe: C:/Users/lucas/AppData/Local/Programs/Python/Python312/libs/python312.lib
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_imgcodecs455.dll.a
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_dnn455.dll.a
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_calib3d455.dll.a
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_features2d455.dll.a
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_flann455.dll.a
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_imgproc455.dll.a
CPMULTI.exe: C:/opencv/build/x64/mingw/lib/libopencv_core455.dll.a
CPMULTI.exe: CMakeFiles/CPMULTI.dir/linkLibs.rsp
CPMULTI.exe: CMakeFiles/CPMULTI.dir/objects1.rsp
CPMULTI.exe: CMakeFiles/CPMULTI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\lucas\Desktop\2025\CPMULTI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable CPMULTI.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CPMULTI.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPMULTI.dir/build: CPMULTI.exe
.PHONY : CMakeFiles/CPMULTI.dir/build

CMakeFiles/CPMULTI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CPMULTI.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CPMULTI.dir/clean

CMakeFiles/CPMULTI.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lucas\Desktop\2025\CPMULTI C:\Users\lucas\Desktop\2025\CPMULTI C:\Users\lucas\Desktop\2025\CPMULTI\build C:\Users\lucas\Desktop\2025\CPMULTI\build C:\Users\lucas\Desktop\2025\CPMULTI\build\CMakeFiles\CPMULTI.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/CPMULTI.dir/depend

