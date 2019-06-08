cmake_minimum_required (VERSION 2.6)
project (Collisions)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(build.o
    src/main.c
    src/player.c
    src/wall.c
    src/dynarray.c
    src/main.h
    src/player.h
    src/wall.h
    src/dynarray.h
    )

if(("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU") OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "CLANG"))
  set(CMAKE_C_FLAGS
    "${CMAKE_C_FLAGS} \
     -Wall \
     -Werror \
     -Wextra \
     -Wconversion \
     -Wunused \
     -Wunused-function \
     -Wunused-label \
     -Wunused-macros \
     -Wunused-parameter \
     -Wunused-value \
     -Wunused-variable \
     -Wcast-align \
     -Wcast-qual \
     -Wredundant-decls \
     -Wnested-externs \
     -Wpointer-arith \
     -Wshadow \
     -Wwrite-strings \
     -Wswitch \
     -Wmissing-field-initializers \
     -fno-common \
     -pedantic \
     -lSDL2-2.0 \
     -g \
     -lm \
     -std=c11")
endif()
