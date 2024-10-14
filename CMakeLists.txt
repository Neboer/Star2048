cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Star2048 C)

# Define the core source files
set(core_src
    src/core/game.c
    src/core/direct_table.c
    src/core/2048_swap_merge.c)

# Add the executable
add_executable(Star2048
    src/cli_main.c
    ${core_src})

# Find raylib
find_package(raylib 3.0 REQUIRED)

if(raylib_FOUND)
    # Add the executable for the GUI version
    add_executable(Star2048GUI
        src/gui_main.c
        src/gui/draw_text.c
        ${core_src})

    # Link the executable with raylib
    target_link_libraries(Star2048GUI raylib m)
endif()