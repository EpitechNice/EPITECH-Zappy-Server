cmake_minimum_required(VERSION 3.20)
project(
    zappy-test
)

set(
    CMAKE_CXX_STANDARD 20
)
set(
    CMAKE_CXX_STANDARD_REQUIRED ON
)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

enable_testing()

# Windows settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(zappy-test
    ../libs/dlist/src/dl_apply.c
    ../libs/dlist/src/dl_clear.c
    ../libs/dlist/src/dl_empty.c
    ../libs/dlist/src/dl_erase.c
    ../libs/dlist/src/dl_extract.c
    ../libs/dlist/src/dl_find.c
    ../libs/dlist/src/dl_insert.c
    ../libs/dlist/src/dl_length.c
    ../libs/dlist/src/dl_pop.c
    ../libs/dlist/src/dl_push.c
    tests.cpp
)

target_include_directories(zappy-test PUBLIC
    ../libs/dlist/includes/
    ../libs/input_output/includes/
    ../includes/
)

target_link_libraries(zappy-test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(zappy-test)