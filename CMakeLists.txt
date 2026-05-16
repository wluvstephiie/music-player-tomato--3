cmake_minimum_required(VERSION 3.10)
project(MusicPlayer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(NCURSES REQUIRED ncurses)

# Add include directories
include_directories(${NCURSES_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/src)

# Source files
set(SOURCES
    src/main.cpp
    src/player.cpp
    src/playlist.cpp
    src/ui.cpp
)

# Create executable
add_executable(music-player ${SOURCES})

# Link libraries
target_link_libraries(music-player ${NCURSES_LIBRARIES})
