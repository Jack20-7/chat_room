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
include CMakeFiles/my_http_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_http_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_http_server.dir/flags.make

CMakeFiles/my_http_server.dir/sample/my_http_server.cc.o: CMakeFiles/my_http_server.dir/flags.make
CMakeFiles/my_http_server.dir/sample/my_http_server.cc.o: ../sample/my_http_server.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/admin/chat_room/JKYi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_http_server.dir/sample/my_http_server.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_http_server.dir/sample/my_http_server.cc.o -c /home/admin/chat_room/JKYi/sample/my_http_server.cc

CMakeFiles/my_http_server.dir/sample/my_http_server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_http_server.dir/sample/my_http_server.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/admin/chat_room/JKYi/sample/my_http_server.cc > CMakeFiles/my_http_server.dir/sample/my_http_server.cc.i

CMakeFiles/my_http_server.dir/sample/my_http_server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_http_server.dir/sample/my_http_server.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/admin/chat_room/JKYi/sample/my_http_server.cc -o CMakeFiles/my_http_server.dir/sample/my_http_server.cc.s

# Object files for target my_http_server
my_http_server_OBJECTS = \
"CMakeFiles/my_http_server.dir/sample/my_http_server.cc.o"

# External object files for target my_http_server
my_http_server_EXTERNAL_OBJECTS =

../bin/my_http_server: CMakeFiles/my_http_server.dir/sample/my_http_server.cc.o
../bin/my_http_server: CMakeFiles/my_http_server.dir/build.make
../bin/my_http_server: ../lib/libJKYi.so
../bin/my_http_server: CMakeFiles/my_http_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/admin/chat_room/JKYi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/my_http_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_http_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_http_server.dir/build: ../bin/my_http_server

.PHONY : CMakeFiles/my_http_server.dir/build

CMakeFiles/my_http_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_http_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_http_server.dir/clean

CMakeFiles/my_http_server.dir/depend:
	cd /home/admin/chat_room/JKYi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/admin/chat_room/JKYi /home/admin/chat_room/JKYi /home/admin/chat_room/JKYi/build /home/admin/chat_room/JKYi/build /home/admin/chat_room/JKYi/build/CMakeFiles/my_http_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_http_server.dir/depend
