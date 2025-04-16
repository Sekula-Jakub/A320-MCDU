cmake_minimum_required(VERSION 3.30)
project(MCDU)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(MCDU main.cpp mcdu.cpp screen.cpp button.cpp font_manager.cpp)

target_link_libraries(MCDU sfml-graphics)