cmake_minimum_required(VERSION 2.6)

project(xg)

if(UNIX)
    add_definitions(-g)
endif()

if(WIN32)
    add_definitions(/wd4996)
endif()

set(DYN_LIBS_ONLY true)
add_subdirectory(ext/dyn)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ext/dyn/src)

# PCRE
#set(PCRE_MINIMAL_DEFAULT "OFF")
#add_subdirectory(ext/pcre)

# Lua
#add_subdirectory(ext/lua)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ext/lua/src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# XG Library
set(XG_SOURCES
    lib/os/os.c
)
add_library(xg ${XG_SOURCES})

# XG Mario
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/app/xgmario)
set(XGMARIO_SOURCES
    app/xgmario/main.c
)
add_executable(xgmario ${XGMARIO_SOURCES})
target_link_libraries(xgmario dyn)
if(WIN32)
    target_link_libraries(xgmario opengl32)
endif()
if(UNIX)
    target_link_libraries(xgmario m)
endif()
