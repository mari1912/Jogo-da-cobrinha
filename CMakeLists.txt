# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(MeuJogo)

#
add_executable(MeuJogo src/main.cpp)

# Especificar onde estao os header files
include_directories(include)

# Bibliotecas locais (estaticas)
add_library(model src/model.cpp)
target_link_libraries(MeuJogo model)
add_library(view src/view.cpp)
target_link_libraries(MeuJogo view)
add_library(controller src/controller.cpp)
target_link_libraries(MeuJogo controller)

# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Bibliotecas linkadas externamente
target_link_libraries(MeuJogo SDL2)
target_link_libraries(MeuJogo SDL2_image)