# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/admin/chat_room/JKYi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/admin/chat_room/JKYi/build

# Include any dependencies generated for this target.
include CMakeFiles/test_ws_client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_ws_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_ws_client.dir/flags.make

CMakeFiles/test_ws_client.dir/tests/test_ws_client.cc.o: CMakeFiles/test_ws_client.dir/flags.make
CMakeFiles/test_ws_client.dir/tests/test_ws_client.cc.o: ../tests/test_ws_client.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/admin/chat_room/JKYi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_ws_client.dir/tests/test_ws_client.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_ws_client.dir/tests/test_ws_client.cc.o -c /home/admin/chat_room/JKYi/tests/test_ws_client.cc

CMakeFiles/test_ws_client.dir/tests/test_ws_client.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_ws_client.dir/tests/test_ws_client.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/admin/chat_room/JKYi/tests/test_ws_client.cc > CMakeFiles/test_ws_client.dir/tests/test_ws_client.cc.i

CMakeFiles/test_ws_client.dir/tests/test_ws_client.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_ws_client.dir/tests/test_ws_client.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/admin/chat_room/JKYi/tests/test_ws_client.cc -o CMakeFiles/test_ws_client.dir/tests/test_ws_client.cc.s

# Object files for target test_ws_client
test_ws_client_OBJECTS = \
"CMakeFiles/test_ws_client.dir/tests/test_ws_client.cc.o"

# External object files for target test_ws_client
test_ws_client_EXTERNAL_OBJECTS =

../bin/test_ws_client: CMakeFiles/test_ws_client.dir/tests/test_ws_client.cc.o
../bin/test_ws_client: CMakeFiles/test_ws_client.dir/build.make
../bin/test_ws_client: ../lib/libJKYi.so
../bin/test_ws_client: CMakeFiles/test_ws_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/admin/chat_room/JKYi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/test_ws_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_ws_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_ws_client.dir/build: ../bin/test_ws_client

.PHONY : CMakeFiles/test_ws_client.dir/build

CMakeFiles/test_ws_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_ws_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_ws_client.dir/clean

CMakeFiles/test_ws_client.dir/depend:
	cd /home/admin/chat_room/JKYi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/admin/chat_room/JKYi /home/admin/chat_room/JKYi /home/admin/chat_room/JKYi/build /home/admin/chat_room/JKYi/build /home/admin/chat_room/JKYi/build/CMakeFiles/test_ws_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_ws_client.dir/depend

