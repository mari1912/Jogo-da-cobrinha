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
include CMakeFiles/MeuJogo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MeuJogo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MeuJogo.dir/flags.make

CMakeFiles/MeuJogo.dir/src/main.cpp.o: CMakeFiles/MeuJogo.dir/flags.make
CMakeFiles/MeuJogo.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariana/Documentos/ea872/Jogo-da-cobrinha/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MeuJogo.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MeuJogo.dir/src/main.cpp.o -c /home/mariana/Documentos/ea872/Jogo-da-cobrinha/src/main.cpp

CMakeFiles/MeuJogo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MeuJogo.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariana/Documentos/ea872/Jogo-da-cobrinha/src/main.cpp > CMakeFiles/MeuJogo.dir/src/main.cpp.i

CMakeFiles/MeuJogo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MeuJogo.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariana/Documentos/ea872/Jogo-da-cobrinha/src/main.cpp -o CMakeFiles/MeuJogo.dir/src/main.cpp.s

# Object files for target MeuJogo
MeuJogo_OBJECTS = \
"CMakeFiles/MeuJogo.dir/src/main.cpp.o"

# External object files for target MeuJogo
MeuJogo_EXTERNAL_OBJECTS =

MeuJogo: CMakeFiles/MeuJogo.dir/src/main.cpp.o
MeuJogo: CMakeFiles/MeuJogo.dir/build.make
MeuJogo: libmodel.a
MeuJogo: libcobra.a
MeuJogo: libfruta.a
MeuJogo: libtabuleiro.a
MeuJogo: libview.a
MeuJogo: libcontroller.a
MeuJogo: CMakeFiles/MeuJogo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mariana/Documentos/ea872/Jogo-da-cobrinha/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MeuJogo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MeuJogo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MeuJogo.dir/build: MeuJogo

.PHONY : CMakeFiles/MeuJogo.dir/build

CMakeFiles/MeuJogo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MeuJogo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MeuJogo.dir/clean

CMakeFiles/MeuJogo.dir/depend:
	cd /home/mariana/Documentos/ea872/Jogo-da-cobrinha/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mariana/Documentos/ea872/Jogo-da-cobrinha /home/mariana/Documentos/ea872/Jogo-da-cobrinha /home/mariana/Documentos/ea872/Jogo-da-cobrinha/bin /home/mariana/Documentos/ea872/Jogo-da-cobrinha/bin /home/mariana/Documentos/ea872/Jogo-da-cobrinha/bin/CMakeFiles/MeuJogo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MeuJogo.dir/depend

