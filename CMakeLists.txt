cmake_minimum_required(VERSION 3.10)
project(MusicPlayer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(ncurses REQUIRED)
find_package(Threads REQUIRED)

# Include directories
include_directories(${NCURSES_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Source files
set(SOURCES
    src/main.cpp
    src/player.cpp
    src/playlist.cpp
    src/ui.cpp
)

set(HEADERS
    src/player.h
    src/playlist.h
    src/ui.h
    src/audio.h
)

# Create executable
add_executable(music-player ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(music-player
    ${NCURSES_LIBRARIES}
    Threads::Threads
)

# Platform-specific settings
if(APPLE)
    target_link_libraries(music-player "-framework CoreAudio")
    target_link_libraries(music-player "-framework AudioToolbox")
endif()
