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
CMAKE_SOURCE_DIR = /home/mariana/Documentos/ea872/Jogo-da-cobrinha/monitor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mariana/Documentos/ea872/Jogo-da-cobrinha/monitor/bin

# Include any dependencies generated for this target.
include CMakeFiles/tabuleiro.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tabuleiro.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tabuleiro.dir/flags.make

CMakeFiles/tabuleiro.dir/src/tabuleiro.cpp.o: CMakeFiles/tabuleiro.dir/flags.make
CMakeFiles/tabuleiro.dir/src/tabuleiro.cpp.o: ../src/tabuleiro.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariana/Documentos/ea872/Jogo-da-cobrinha/monitor/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tabuleiro.dir/src/tabuleiro.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tabuleiro.dir/src/tabuleiro.cpp.o -c /home/mariana/Documentos/ea872/Jogo-da-cobrinha/monitor/src/tabuleiro.cpp

CMakeFiles/tabuleiro.dir/src/tabuleiro.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tabuleiro.dir/src/tabuleiro.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariana/Documentos/ea872/Jogo-da-cobrinha/monitor/src/tabuleiro.cpp > CMakeFiles/tabuleiro.dir/src/tabuleiro.cpp.i

CMakeFiles/tabuleiro.dir/src/tabuleiro.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tabuleiro.dir/src/tabuleiro.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariana/Documentos/ea872/Jogo-da-cobrinha/monitor/src/tabuleiro.cpp -o CMakeFiles/tabuleiro.dir/src/tabuleiro.cpp.s

# Object files for target tabuleiro
tabuleiro_OBJECTS = \
"CMakeFiles/tabuleiro.dir/src/tabuleiro.cpp.o"

# External object files for target tabuleiro
tabuleiro_EXTERNAL_OBJECTS =

libtabuleiro.a: CMakeFiles/tabuleiro.dir/src/tabuleiro.cpp.o
libtabuleiro.a: CMakeFiles/tabuleiro.dir/build.make
libtabuleiro.a: CMakeFiles/tabuleiro.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mariana/Documentos/ea872/Jogo-da-cobrinha/monitor/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtabuleiro.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tabuleiro.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tabuleiro.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tabuleiro.dir/build: libtabuleiro.a

.PHONY : CMakeFiles/tabuleiro.dir/build

CMakeFiles/tabuleiro.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tabuleiro.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tabuleiro.dir/clean

CMakeFiles/tabuleiro.dir/depend:
	cd /home/mariana/Documentos/ea872/Jogo-da-cobrinha/monitor/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mariana/Documentos/ea872/Jogo-da-cobrinha/monitor /home/mariana/Documentos/ea872/Jogo-da-cobrinha/monitor /home/mariana/Documentos/ea872/Jogo-da-cobrinha/monitor/bin /home/mariana/Documentos/ea872/Jogo-da-cobrinha/monitor/bin /home/mariana/Documentos/ea872/Jogo-da-cobrinha/monitor/bin/CMakeFiles/tabuleiro.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tabuleiro.dir/depend

