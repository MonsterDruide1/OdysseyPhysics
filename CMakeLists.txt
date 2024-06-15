cmake_minimum_required(VERSION 3.5)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE "RelWithDebInfo")

project(OdysseyPhysics)

add_compile_options(-O0)
#add_compile_options(-stdlib=libc++)
#add_link_options(-stdlib=libc++)

add_subdirectory(lib/raylib)
add_subdirectory(lib/nlib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
include_directories(lib/raylib/src)
include_directories(lib/nlib/include)
include_directories(lib/nlib/lib/oead/src/include)

file(GLOB_RECURSE SOURCES_SMO ${PROJECT_SOURCE_DIR}/lib/smo/*.cpp ${PROJECT_SOURCE_DIR}/lib/smo/*.c ${PROJECT_SOURCE_DIR}/lib/smo/*.h ${PROJECT_SOURCE_DIR}/lib/smo/*.hpp)
file(GLOB_RECURSE SOURCES_APP ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/*.c ${PROJECT_SOURCE_DIR}/src/*.h ${PROJECT_SOURCE_DIR}/src/*.hpp)


add_executable(OdysseyPhysics ${SOURCES_APP})
#add_executable(OdysseyPhysics src/tas-studio.cpp src/ui/Scene.cpp src/ui/Camera.cpp src/file/KCollision.cpp)

find_package(Threads REQUIRED)
target_link_libraries(OdysseyPhysics PRIVATE Threads::Threads)
target_link_libraries(OdysseyPhysics PUBLIC raylib)
target_link_libraries(OdysseyPhysics PUBLIC nlib)
file(COPY res DESTINATION .)

include(ExternalProject)
ExternalProject_Add(odyssey
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/lib/smo
    CMAKE_CACHE_ARGS -DCMAKE_TOOLCHAIN_FILE:FILEPATH=${PROJECT_SOURCE_DIR}/lib/smo/toolchain/ToolchainPC64.cmake
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/odyssey
    INSTALL_DIR ${CMAKE_BINARY_DIR}/odyssey
    BUILD_BYPRODUCTS ${CMAKE_BINARY_DIR}/odyssey/lib/libodyssey_lib.a
    BUILD_ALWAYS TRUE
)
add_definitions(-D NNSDK)
include_directories(lib/smo/src)
include_directories(lib/smo/lib/al)
#include_directories(lib/smo/lib/aarch64)
include_directories(lib/smo/lib/agl/include)
include_directories(lib/smo/lib/eui/include)
include_directories(lib/smo/lib/NintendoSDK/include)
include_directories(lib/smo/lib/sead/include)

ExternalProject_Get_Property(odyssey install_dir)

add_library(odysseylib STATIC IMPORTED)
set_property(TARGET odysseylib PROPERTY IMPORTED_LOCATION ${install_dir}/lib/libodyssey_lib.a)
add_dependencies(OdysseyPhysics odyssey odysseylib)
target_link_libraries(OdysseyPhysics PUBLIC odysseylib)
