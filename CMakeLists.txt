cmake_minimum_required(VERSION 3.5)
project(shell_lapostolle_saby C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell src/lecture.c src/matrix.c src/structure.c main.c)
