cmake_minimum_required(VERSION 3.30)
project(MCDU)

include(FetchContent)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 20)

add_executable(MCDU
        main.cpp
        mcdu.cpp
        screen.cpp
        button.cpp
        font_manager.cpp
        pages/mcdu_menu.cpp
        pages/mcdu_menu_branch/atsu.cpp
        pages/mcdu_menu_branch/fmgc.cpp
        pages/mcdu_menu_branch/aoc_menu.cpp
        pages/mcdu_menu_branch/flt_init.cpp
        pages/input.cpp
        database_sqlite3_files/sqlite3.c
        data_base_manager.cpp
)

target_include_directories(MCDU PRIVATE
        ${PROJECT_SOURCE_DIR}/headers
        ${PROJECT_SOURCE_DIR}/pages/mcdu_menu_branch
)

target_link_libraries(MCDU sfml-graphics)