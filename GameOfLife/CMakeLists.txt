cmake_minimum_required (VERSION 2.6)
project (GameOfLife)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(build.o
    src/main.c
    src/cell.c
	src/dynarray.c
    src/main.h
    src/cell.h
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
     -std=c11")
endif()
