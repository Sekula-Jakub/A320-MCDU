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
        pages/mcdu_menu_branch/wx.cpp
        pages/mcdu_menu_branch/weather_req.cpp
        pages/flight_plan_branch/departure_page_a.cpp
        pages/flight_plan_branch/departure_page_b.cpp
        pages/flight_plan_branch/arrival_page_a.cpp
        pages/flight_plan_branch/arrival_page_b.cpp
        pages/input.cpp
        pages/data_page.cpp
        pages/init_page.cpp
        pages/init_page_b.cpp
        pages/flight_plan.cpp
        database_sqlite3_files/sqlite3.c
        data_base_manager.cpp
)

target_include_directories(MCDU PRIVATE
        ${PROJECT_SOURCE_DIR}/pages
        ${PROJECT_SOURCE_DIR}/pages/mcdu_menu_branch
        ${PROJECT_SOURCE_DIR}/pages/flight_plan_branch
)

target_link_libraries(MCDU sfml-graphics)