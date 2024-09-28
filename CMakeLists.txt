cmake_minimum_required(VERSION 3.8)
include(ExternalProject)

project(starter VERSION 0.0)

# config
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(PROJECT_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_BUILD ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_executable(starter)
set_target_properties(starter PROPERTIES LINKER_LANGUAGE CXX)

# (Example) link raylib and a few other libraries
# target_link_libraries(starter raylib GL m pthread dl rt X11)

# add source files
set(PROJECT_SRC_FILES 
  core/cbase.c
  core/clist.c
  main.c
)
list(TRANSFORM PROJECT_SRC_FILES PREPEND ${PROJECT_SRC}/)

target_include_directories(starter PRIVATE ${PROJECT_SRC})
target_sources(starter PRIVATE ${PROJECT_SRC_FILES})

# (Example) add raylib as an external project
# ExternalProject_Add(raylib
#     PREFIX vendor
#     GIT_REPOSITORY https://github.com/raysan5/raylib.git
#     GIT_TAG origin/master
#     UPDATE_COMMAND ""
#     PATCH_COMMAND ""
#     INSTALL_COMMAND "")
# target_include_directories(starter PRIVATE ${PROJECT_BUILD}/vendor/src/raylib/src/)
# target_link_directories(starter PRIVATE ${PROJECT_BUILD}/vendor/src/raylib-build/raylib)
