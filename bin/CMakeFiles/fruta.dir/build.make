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
CMAKE_SOURCE_DIR = /home/daniele/comp/ea872/jogodacobrinha/Jogo-da-cobrinha

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daniele/comp/ea872/jogodacobrinha/Jogo-da-cobrinha/bin

# Include any dependencies generated for this target.
include CMakeFiles/fruta.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fruta.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fruta.dir/flags.make

CMakeFiles/fruta.dir/src/fruta.cpp.o: CMakeFiles/fruta.dir/flags.make
CMakeFiles/fruta.dir/src/fruta.cpp.o: ../src/fruta.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniele/comp/ea872/jogodacobrinha/Jogo-da-cobrinha/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fruta.dir/src/fruta.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fruta.dir/src/fruta.cpp.o -c /home/daniele/comp/ea872/jogodacobrinha/Jogo-da-cobrinha/src/fruta.cpp

CMakeFiles/fruta.dir/src/fruta.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fruta.dir/src/fruta.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daniele/comp/ea872/jogodacobrinha/Jogo-da-cobrinha/src/fruta.cpp > CMakeFiles/fruta.dir/src/fruta.cpp.i

CMakeFiles/fruta.dir/src/fruta.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fruta.dir/src/fruta.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daniele/comp/ea872/jogodacobrinha/Jogo-da-cobrinha/src/fruta.cpp -o CMakeFiles/fruta.dir/src/fruta.cpp.s

# Object files for target fruta
fruta_OBJECTS = \
"CMakeFiles/fruta.dir/src/fruta.cpp.o"

# External object files for target fruta
fruta_EXTERNAL_OBJECTS =

libfruta.a: CMakeFiles/fruta.dir/src/fruta.cpp.o
libfruta.a: CMakeFiles/fruta.dir/build.make
libfruta.a: CMakeFiles/fruta.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daniele/comp/ea872/jogodacobrinha/Jogo-da-cobrinha/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libfruta.a"
	$(CMAKE_COMMAND) -P CMakeFiles/fruta.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fruta.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fruta.dir/build: libfruta.a

.PHONY : CMakeFiles/fruta.dir/build

CMakeFiles/fruta.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fruta.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fruta.dir/clean

CMakeFiles/fruta.dir/depend:
	cd /home/daniele/comp/ea872/jogodacobrinha/Jogo-da-cobrinha/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daniele/comp/ea872/jogodacobrinha/Jogo-da-cobrinha /home/daniele/comp/ea872/jogodacobrinha/Jogo-da-cobrinha /home/daniele/comp/ea872/jogodacobrinha/Jogo-da-cobrinha/bin /home/daniele/comp/ea872/jogodacobrinha/Jogo-da-cobrinha/bin /home/daniele/comp/ea872/jogodacobrinha/Jogo-da-cobrinha/bin/CMakeFiles/fruta.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fruta.dir/depend

