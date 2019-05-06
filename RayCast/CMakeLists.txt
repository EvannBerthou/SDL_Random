cmake_minimum_required (VERSION 2.6)
project (SDLTest)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(build.o
    src/main.c
    src/vector.c
    src/line.c
    src/raycast.c
    src/dynarray.c
    src/circle.c
    src/main.h
    src/vector.h
    src/line.h
    src/raycast.h
    src/dynarray.h
    src/circle.h
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
     -lm \
     -g \
     -std=c11")
endif()
