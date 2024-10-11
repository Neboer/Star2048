cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Star2048 C)

# Add the executable
add_executable(Star2048
    src/main.c
    src/direct_table.c
    src/game.c
    src/2048_swap_merge.c)