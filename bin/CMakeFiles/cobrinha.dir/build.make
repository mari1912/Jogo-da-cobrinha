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
CMAKE_SOURCE_DIR = /home/mariana/Documentos/ea872/Jogo-da-cobrinha

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mariana/Documentos/ea872/Jogo-da-cobrinha/bin

# Include any dependencies generated for this target.
include CMakeFiles/cobrinha.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cobrinha.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cobrinha.dir/flags.make

CMakeFiles/cobrinha.dir/src/cobrinha.cpp.o: CMakeFiles/cobrinha.dir/flags.make
CMakeFiles/cobrinha.dir/src/cobrinha.cpp.o: ../src/cobrinha.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariana/Documentos/ea872/Jogo-da-cobrinha/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cobrinha.dir/src/cobrinha.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cobrinha.dir/src/cobrinha.cpp.o -c /home/mariana/Documentos/ea872/Jogo-da-cobrinha/src/cobrinha.cpp

CMakeFiles/cobrinha.dir/src/cobrinha.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cobrinha.dir/src/cobrinha.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariana/Documentos/ea872/Jogo-da-cobrinha/src/cobrinha.cpp > CMakeFiles/cobrinha.dir/src/cobrinha.cpp.i

CMakeFiles/cobrinha.dir/src/cobrinha.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cobrinha.dir/src/cobrinha.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariana/Documentos/ea872/Jogo-da-cobrinha/src/cobrinha.cpp -o CMakeFiles/cobrinha.dir/src/cobrinha.cpp.s

# Object files for target cobrinha
cobrinha_OBJECTS = \
"CMakeFiles/cobrinha.dir/src/cobrinha.cpp.o"

# External object files for target cobrinha
cobrinha_EXTERNAL_OBJECTS =

libcobrinha.a: CMakeFiles/cobrinha.dir/src/cobrinha.cpp.o
libcobrinha.a: CMakeFiles/cobrinha.dir/build.make
libcobrinha.a: CMakeFiles/cobrinha.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mariana/Documentos/ea872/Jogo-da-cobrinha/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcobrinha.a"
	$(CMAKE_COMMAND) -P CMakeFiles/cobrinha.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cobrinha.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cobrinha.dir/build: libcobrinha.a

.PHONY : CMakeFiles/cobrinha.dir/build

CMakeFiles/cobrinha.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cobrinha.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cobrinha.dir/clean

CMakeFiles/cobrinha.dir/depend:
	cd /home/mariana/Documentos/ea872/Jogo-da-cobrinha/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mariana/Documentos/ea872/Jogo-da-cobrinha /home/mariana/Documentos/ea872/Jogo-da-cobrinha /home/mariana/Documentos/ea872/Jogo-da-cobrinha/bin /home/mariana/Documentos/ea872/Jogo-da-cobrinha/bin /home/mariana/Documentos/ea872/Jogo-da-cobrinha/bin/CMakeFiles/cobrinha.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cobrinha.dir/depend

