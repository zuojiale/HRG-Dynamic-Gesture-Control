# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build

# Include any dependencies generated for this target.
include CMakeFiles/2_HRG_MP3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2_HRG_MP3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2_HRG_MP3.dir/flags.make

ui_widget.h: ../widget.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ui_widget.h"
	/home/zjl/QT_Install/5.9/gcc_64/bin/uic -o /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/ui_widget.h /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/widget.ui

CMakeFiles/2_HRG_MP3.dir/main.cpp.o: CMakeFiles/2_HRG_MP3.dir/flags.make
CMakeFiles/2_HRG_MP3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/2_HRG_MP3.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_HRG_MP3.dir/main.cpp.o -c /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/main.cpp

CMakeFiles/2_HRG_MP3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_HRG_MP3.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/main.cpp > CMakeFiles/2_HRG_MP3.dir/main.cpp.i

CMakeFiles/2_HRG_MP3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_HRG_MP3.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/main.cpp -o CMakeFiles/2_HRG_MP3.dir/main.cpp.s

CMakeFiles/2_HRG_MP3.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/2_HRG_MP3.dir/main.cpp.o.requires

CMakeFiles/2_HRG_MP3.dir/main.cpp.o.provides: CMakeFiles/2_HRG_MP3.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/2_HRG_MP3.dir/build.make CMakeFiles/2_HRG_MP3.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/2_HRG_MP3.dir/main.cpp.o.provides

CMakeFiles/2_HRG_MP3.dir/main.cpp.o.provides.build: CMakeFiles/2_HRG_MP3.dir/main.cpp.o


CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o: CMakeFiles/2_HRG_MP3.dir/flags.make
CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o: ../mp3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o -c /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/mp3.cpp

CMakeFiles/2_HRG_MP3.dir/mp3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_HRG_MP3.dir/mp3.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/mp3.cpp > CMakeFiles/2_HRG_MP3.dir/mp3.cpp.i

CMakeFiles/2_HRG_MP3.dir/mp3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_HRG_MP3.dir/mp3.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/mp3.cpp -o CMakeFiles/2_HRG_MP3.dir/mp3.cpp.s

CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o.requires:

.PHONY : CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o.requires

CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o.provides: CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o.requires
	$(MAKE) -f CMakeFiles/2_HRG_MP3.dir/build.make CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o.provides.build
.PHONY : CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o.provides

CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o.provides.build: CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o


CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o: CMakeFiles/2_HRG_MP3.dir/flags.make
CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o: ../dtwrecoge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o -c /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/dtwrecoge.cpp

CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/dtwrecoge.cpp > CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.i

CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/dtwrecoge.cpp -o CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.s

CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o.requires:

.PHONY : CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o.requires

CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o.provides: CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o.requires
	$(MAKE) -f CMakeFiles/2_HRG_MP3.dir/build.make CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o.provides.build
.PHONY : CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o.provides

CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o.provides.build: CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o


CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o: CMakeFiles/2_HRG_MP3.dir/flags.make
CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o: ../handfinder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o -c /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/handfinder.cpp

CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/handfinder.cpp > CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.i

CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/handfinder.cpp -o CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.s

CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o.requires:

.PHONY : CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o.requires

CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o.provides: CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o.requires
	$(MAKE) -f CMakeFiles/2_HRG_MP3.dir/build.make CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o.provides.build
.PHONY : CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o.provides

CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o.provides.build: CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o


CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o: CMakeFiles/2_HRG_MP3.dir/flags.make
CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o: ../connectthread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o -c /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/connectthread.cpp

CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/connectthread.cpp > CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.i

CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/connectthread.cpp -o CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.s

CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o.requires:

.PHONY : CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o.requires

CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o.provides: CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o.requires
	$(MAKE) -f CMakeFiles/2_HRG_MP3.dir/build.make CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o.provides.build
.PHONY : CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o.provides

CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o.provides.build: CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o


CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o: CMakeFiles/2_HRG_MP3.dir/flags.make
CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o: ../setparam.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o -c /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/setparam.cpp

CMakeFiles/2_HRG_MP3.dir/setparam.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_HRG_MP3.dir/setparam.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/setparam.cpp > CMakeFiles/2_HRG_MP3.dir/setparam.cpp.i

CMakeFiles/2_HRG_MP3.dir/setparam.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_HRG_MP3.dir/setparam.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/setparam.cpp -o CMakeFiles/2_HRG_MP3.dir/setparam.cpp.s

CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o.requires:

.PHONY : CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o.requires

CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o.provides: CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o.requires
	$(MAKE) -f CMakeFiles/2_HRG_MP3.dir/build.make CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o.provides.build
.PHONY : CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o.provides

CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o.provides.build: CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o


CMakeFiles/2_HRG_MP3.dir/widget.cpp.o: CMakeFiles/2_HRG_MP3.dir/flags.make
CMakeFiles/2_HRG_MP3.dir/widget.cpp.o: ../widget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/2_HRG_MP3.dir/widget.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_HRG_MP3.dir/widget.cpp.o -c /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/widget.cpp

CMakeFiles/2_HRG_MP3.dir/widget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_HRG_MP3.dir/widget.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/widget.cpp > CMakeFiles/2_HRG_MP3.dir/widget.cpp.i

CMakeFiles/2_HRG_MP3.dir/widget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_HRG_MP3.dir/widget.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/widget.cpp -o CMakeFiles/2_HRG_MP3.dir/widget.cpp.s

CMakeFiles/2_HRG_MP3.dir/widget.cpp.o.requires:

.PHONY : CMakeFiles/2_HRG_MP3.dir/widget.cpp.o.requires

CMakeFiles/2_HRG_MP3.dir/widget.cpp.o.provides: CMakeFiles/2_HRG_MP3.dir/widget.cpp.o.requires
	$(MAKE) -f CMakeFiles/2_HRG_MP3.dir/build.make CMakeFiles/2_HRG_MP3.dir/widget.cpp.o.provides.build
.PHONY : CMakeFiles/2_HRG_MP3.dir/widget.cpp.o.provides

CMakeFiles/2_HRG_MP3.dir/widget.cpp.o.provides.build: CMakeFiles/2_HRG_MP3.dir/widget.cpp.o


CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o: CMakeFiles/2_HRG_MP3.dir/flags.make
CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o: 2_HRG_MP3_automoc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o -c /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/2_HRG_MP3_automoc.cpp

CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/2_HRG_MP3_automoc.cpp > CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.i

CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/2_HRG_MP3_automoc.cpp -o CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.s

CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o.requires:

.PHONY : CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o.requires

CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o.provides: CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o.requires
	$(MAKE) -f CMakeFiles/2_HRG_MP3.dir/build.make CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o.provides.build
.PHONY : CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o.provides

CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o.provides.build: CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o


# Object files for target 2_HRG_MP3
2_HRG_MP3_OBJECTS = \
"CMakeFiles/2_HRG_MP3.dir/main.cpp.o" \
"CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o" \
"CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o" \
"CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o" \
"CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o" \
"CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o" \
"CMakeFiles/2_HRG_MP3.dir/widget.cpp.o" \
"CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o"

# External object files for target 2_HRG_MP3
2_HRG_MP3_EXTERNAL_OBJECTS =

../bin/2_HRG_MP3: CMakeFiles/2_HRG_MP3.dir/main.cpp.o
../bin/2_HRG_MP3: CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o
../bin/2_HRG_MP3: CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o
../bin/2_HRG_MP3: CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o
../bin/2_HRG_MP3: CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o
../bin/2_HRG_MP3: CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o
../bin/2_HRG_MP3: CMakeFiles/2_HRG_MP3.dir/widget.cpp.o
../bin/2_HRG_MP3: CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o
../bin/2_HRG_MP3: CMakeFiles/2_HRG_MP3.dir/build.make
../bin/2_HRG_MP3: /home/zjl/QT_Install/5.9/gcc_64/lib/libQt5Widgets.so.5.9.0
../bin/2_HRG_MP3: /home/zjl/QT_Install/5.9/gcc_64/lib/libQt5Concurrent.so.5.9.0
../bin/2_HRG_MP3: /home/zjl/QT_Install/5.9/gcc_64/lib/libQt5Multimedia.so.5.9.0
../bin/2_HRG_MP3: ../lib/libtofsdk.so
../bin/2_HRG_MP3: /usr/local/lib/libopencv_ml.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_shape.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_videostab.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_objdetect.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_stitching.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_superres.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_calib3d.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_dnn.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_features2d.so.3.4.1
../bin/2_HRG_MP3: /home/zjl/libtorch/lib/libtorch.so
../bin/2_HRG_MP3: /home/zjl/libtorch/lib/libc10.so
../bin/2_HRG_MP3: /home/zjl/QT_Install/5.9/gcc_64/lib/libQt5Gui.so.5.9.0
../bin/2_HRG_MP3: /home/zjl/QT_Install/5.9/gcc_64/lib/libQt5Network.so.5.9.0
../bin/2_HRG_MP3: /home/zjl/QT_Install/5.9/gcc_64/lib/libQt5Core.so.5.9.0
../bin/2_HRG_MP3: /usr/local/lib/libopencv_photo.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_highgui.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_flann.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_video.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_videoio.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_imgcodecs.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_imgproc.so.3.4.1
../bin/2_HRG_MP3: /usr/local/lib/libopencv_core.so.3.4.1
../bin/2_HRG_MP3: /home/zjl/libtorch/lib/libc10.so
../bin/2_HRG_MP3: CMakeFiles/2_HRG_MP3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ../bin/2_HRG_MP3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2_HRG_MP3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2_HRG_MP3.dir/build: ../bin/2_HRG_MP3

.PHONY : CMakeFiles/2_HRG_MP3.dir/build

CMakeFiles/2_HRG_MP3.dir/requires: CMakeFiles/2_HRG_MP3.dir/main.cpp.o.requires
CMakeFiles/2_HRG_MP3.dir/requires: CMakeFiles/2_HRG_MP3.dir/mp3.cpp.o.requires
CMakeFiles/2_HRG_MP3.dir/requires: CMakeFiles/2_HRG_MP3.dir/dtwrecoge.cpp.o.requires
CMakeFiles/2_HRG_MP3.dir/requires: CMakeFiles/2_HRG_MP3.dir/handfinder.cpp.o.requires
CMakeFiles/2_HRG_MP3.dir/requires: CMakeFiles/2_HRG_MP3.dir/connectthread.cpp.o.requires
CMakeFiles/2_HRG_MP3.dir/requires: CMakeFiles/2_HRG_MP3.dir/setparam.cpp.o.requires
CMakeFiles/2_HRG_MP3.dir/requires: CMakeFiles/2_HRG_MP3.dir/widget.cpp.o.requires
CMakeFiles/2_HRG_MP3.dir/requires: CMakeFiles/2_HRG_MP3.dir/2_HRG_MP3_automoc.cpp.o.requires

.PHONY : CMakeFiles/2_HRG_MP3.dir/requires

CMakeFiles/2_HRG_MP3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2_HRG_MP3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2_HRG_MP3.dir/clean

CMakeFiles/2_HRG_MP3.dir/depend: ui_widget.h
	cd /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3 /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3 /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build /home/zjl/HRG_hand/Hrg手势识别/8_Mp3/2_HRG_MP3/build/CMakeFiles/2_HRG_MP3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2_HRG_MP3.dir/depend
