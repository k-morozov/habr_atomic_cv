cmake_minimum_required(VERSION 3.22)

project(habr_example)
set(APP_NAME example)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_VERBOSE_MAKEFILE ON)

message (STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
# https://clang.llvm.org/docs/DiagnosticsReference.html
add_compile_options(-Wall -Wextra -Wpedantic)

include_directories(src/game)

set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -latomic")
find_package(Threads)

add_executable(${APP_NAME}
        src/example.cpp
        src/game/game_base/game_base.cpp
        src/game/game_cv/game_cv.cpp
        src/game/game_atomic/game_atomic.cpp
        src/game/game_time/game_time.cpp
)
target_link_libraries(${APP_NAME} ${CMAKE_THREAD_LIBS_INIT} )

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    add_compile_options(-D_GLIBCXX_ASSERTIONS -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_LIBCPP_DEBUG=1)
    set_target_properties(${APP_NAME} PROPERTIES
            CXX_STANDARD 20
            COMPILE_OPTIONS "-fsanitize=thread"
            LINK_OPTIONS "-fsanitize=thread"
            )
else()
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()