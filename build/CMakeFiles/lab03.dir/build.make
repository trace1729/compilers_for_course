# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /root/trace/learning/course/compilers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/trace/learning/course/compilers/build

# Include any dependencies generated for this target.
include CMakeFiles/lab03.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab03.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab03.dir/flags.make

CMakeFiles/lab03.dir/lab03.cpp.o: CMakeFiles/lab03.dir/flags.make
CMakeFiles/lab03.dir/lab03.cpp.o: ../lab03.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/trace/learning/course/compilers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab03.dir/lab03.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab03.dir/lab03.cpp.o -c /root/trace/learning/course/compilers/lab03.cpp

CMakeFiles/lab03.dir/lab03.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab03.dir/lab03.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/trace/learning/course/compilers/lab03.cpp > CMakeFiles/lab03.dir/lab03.cpp.i

CMakeFiles/lab03.dir/lab03.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab03.dir/lab03.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/trace/learning/course/compilers/lab03.cpp -o CMakeFiles/lab03.dir/lab03.cpp.s

CMakeFiles/lab03.dir/trie.cpp.o: CMakeFiles/lab03.dir/flags.make
CMakeFiles/lab03.dir/trie.cpp.o: ../trie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/trace/learning/course/compilers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab03.dir/trie.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab03.dir/trie.cpp.o -c /root/trace/learning/course/compilers/trie.cpp

CMakeFiles/lab03.dir/trie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab03.dir/trie.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/trace/learning/course/compilers/trie.cpp > CMakeFiles/lab03.dir/trie.cpp.i

CMakeFiles/lab03.dir/trie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab03.dir/trie.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/trace/learning/course/compilers/trie.cpp -o CMakeFiles/lab03.dir/trie.cpp.s

CMakeFiles/lab03.dir/grammar.cpp.o: CMakeFiles/lab03.dir/flags.make
CMakeFiles/lab03.dir/grammar.cpp.o: ../grammar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/trace/learning/course/compilers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab03.dir/grammar.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab03.dir/grammar.cpp.o -c /root/trace/learning/course/compilers/grammar.cpp

CMakeFiles/lab03.dir/grammar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab03.dir/grammar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/trace/learning/course/compilers/grammar.cpp > CMakeFiles/lab03.dir/grammar.cpp.i

CMakeFiles/lab03.dir/grammar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab03.dir/grammar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/trace/learning/course/compilers/grammar.cpp -o CMakeFiles/lab03.dir/grammar.cpp.s

# Object files for target lab03
lab03_OBJECTS = \
"CMakeFiles/lab03.dir/lab03.cpp.o" \
"CMakeFiles/lab03.dir/trie.cpp.o" \
"CMakeFiles/lab03.dir/grammar.cpp.o"

# External object files for target lab03
lab03_EXTERNAL_OBJECTS =

lab03: CMakeFiles/lab03.dir/lab03.cpp.o
lab03: CMakeFiles/lab03.dir/trie.cpp.o
lab03: CMakeFiles/lab03.dir/grammar.cpp.o
lab03: CMakeFiles/lab03.dir/build.make
lab03: CMakeFiles/lab03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/trace/learning/course/compilers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable lab03"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab03.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab03.dir/build: lab03

.PHONY : CMakeFiles/lab03.dir/build

CMakeFiles/lab03.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab03.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab03.dir/clean

CMakeFiles/lab03.dir/depend:
	cd /root/trace/learning/course/compilers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/trace/learning/course/compilers /root/trace/learning/course/compilers /root/trace/learning/course/compilers/build /root/trace/learning/course/compilers/build /root/trace/learning/course/compilers/build/CMakeFiles/lab03.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab03.dir/depend
