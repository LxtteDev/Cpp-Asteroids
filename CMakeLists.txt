cmake_minimum_required(VERSION 3.0.0)
project(Asteroids VERSION 0.1.0)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
 SFML
 GIT_REPOSITORY https://github.com/SFML/SFML.git
 GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

include(CTest)
enable_testing()

add_executable(Asteroids
    src/main.cpp
    src/window/window.h src/window/window.cpp
    src/player/player.h src/player/player.cpp
)

target_link_libraries(Asteroids sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
