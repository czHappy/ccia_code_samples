# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/build

# Include any dependencies generated for this target.
include test2/CMakeFiles/test2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test2/CMakeFiles/test2.dir/compiler_depend.make

# Include the progress variables for this target.
include test2/CMakeFiles/test2.dir/progress.make

# Include the compile flags for this target's objects.
include test2/CMakeFiles/test2.dir/flags.make

test2/CMakeFiles/test2.dir/sort.cpp.o: test2/CMakeFiles/test2.dir/flags.make
test2/CMakeFiles/test2.dir/sort.cpp.o: ../test2/sort.cpp
test2/CMakeFiles/test2.dir/sort.cpp.o: test2/CMakeFiles/test2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test2/CMakeFiles/test2.dir/sort.cpp.o"
	cd /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/build/test2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test2/CMakeFiles/test2.dir/sort.cpp.o -MF CMakeFiles/test2.dir/sort.cpp.o.d -o CMakeFiles/test2.dir/sort.cpp.o -c /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/test2/sort.cpp

test2/CMakeFiles/test2.dir/sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/sort.cpp.i"
	cd /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/build/test2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/test2/sort.cpp > CMakeFiles/test2.dir/sort.cpp.i

test2/CMakeFiles/test2.dir/sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/sort.cpp.s"
	cd /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/build/test2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/test2/sort.cpp -o CMakeFiles/test2.dir/sort.cpp.s

# Object files for target test2
test2_OBJECTS = \
"CMakeFiles/test2.dir/sort.cpp.o"

# External object files for target test2
test2_EXTERNAL_OBJECTS =

bin/test2: test2/CMakeFiles/test2.dir/sort.cpp.o
bin/test2: test2/CMakeFiles/test2.dir/build.make
bin/test2: lib/libsort.so
bin/test2: test2/CMakeFiles/test2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/test2"
	cd /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/build/test2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test2/CMakeFiles/test2.dir/build: bin/test2
.PHONY : test2/CMakeFiles/test2.dir/build

test2/CMakeFiles/test2.dir/clean:
	cd /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/build/test2 && $(CMAKE_COMMAND) -P CMakeFiles/test2.dir/cmake_clean.cmake
.PHONY : test2/CMakeFiles/test2.dir/clean

test2/CMakeFiles/test2.dir/depend:
	cd /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/test2 /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/build /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/build/test2 /home/sk49/workspace/chengzhen/ccia_code_samples/listings/cmake_example/advance/build/test2/CMakeFiles/test2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test2/CMakeFiles/test2.dir/depend

