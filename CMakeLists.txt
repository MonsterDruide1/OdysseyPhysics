cmake_minimum_required(VERSION 3.5)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
set(CMAKE_C_COMPILER_TARGET aarch64-linux-gnu)
set(CMAKE_CXX_COMPILER_TARGET aarch64-linux-gnu)
set(CMAKE_LIBRARY_ARCHITECTURE aarch64-linux-gnu)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
#add_link_options(-fuse-ld=lld)

# work around cross-compilation issue
# raylib wants to use `-std=c99`, which does not expose `clockid_t` from `<time.h>`, whereas any `-std=gnu` dialect does
add_compile_options(-D_GNU_SOURCE)
#add_compile_options(-nostdinc++ -nodefaultlibs)
add_link_options(-lc -lc++ -lc++abi)
#add_compile_options(-stdlib=libc++)
#add_link_options(-nostdlib++)

set(CMAKE_BUILD_TYPE "RelWithDebInfo")

set(OPENGL_VERSION "ES 2.0")

project(OdysseyPhysics)
add_executable(OdysseyPhysics)

# these appear before anything else, so they are overridden by anything in the decomp or simulator
#add_library(swsplrs STATIC IMPORTED)
#set_property(TARGET swsplrs PROPERTY IMPORTED_LOCATION /home/monsterdruide1/swsplrs/out/obj/assembled.o)
#add_dependencies(OdysseyPhysics swsplrs)
#target_link_libraries(OdysseyPhysics PUBLIC swsplrs)

#add_library(swsplrs STATIC /home/monsterdruide1/swsplrs/out/obj/assembled.o)
#target_link_libraries(OdysseyPhysics PUBLIC swsplrs)
#set_target_properties(swsplrs PROPERTIES
#    LINKER_LANGUAGE CXX
#)

#[[
add_library(swsplrs_sdk STATIC IMPORTED)
set_property(TARGET swsplrs_sdk PROPERTY IMPORTED_LOCATION /home/monsterdruide1/swsplrs/out/libsdk.so)
add_dependencies(OdysseyPhysics swsplrs_sdk)
target_link_libraries(OdysseyPhysics PUBLIC swsplrs_sdk)

add_library(swsplrs_subsdk0 STATIC IMPORTED)
set_property(TARGET swsplrs_subsdk0 PROPERTY IMPORTED_LOCATION /home/monsterdruide1/swsplrs/out/libsubsdk0.so)
add_dependencies(OdysseyPhysics swsplrs_subsdk0)
target_link_libraries(OdysseyPhysics PUBLIC swsplrs_subsdk0)
#]]

target_link_options(OdysseyPhysics PRIVATE -Wl,--allow-multiple-definition)
#target_link_options(OdysseyPhysics PRIVATE -Wl,--unresolved-symbols=ignore-all)

add_compile_options(-O0 -g)
#add_compile_options(-stdlib=libc++)
#add_link_options(-stdlib=libc++)

add_subdirectory(lib/raylib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)
include_directories(src/util)
include_directories(lib/raylib/src)

file(GLOB_RECURSE SOURCES_SMO ${PROJECT_SOURCE_DIR}/lib/smo/*.cpp ${PROJECT_SOURCE_DIR}/lib/smo/*.c ${PROJECT_SOURCE_DIR}/lib/smo/*.h ${PROJECT_SOURCE_DIR}/lib/smo/*.hpp)
file(GLOB_RECURSE SOURCES_APP ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/*.c ${PROJECT_SOURCE_DIR}/src/*.h ${PROJECT_SOURCE_DIR}/src/*.hpp)


target_sources(OdysseyPhysics PRIVATE ${SOURCES_APP})
#target_sources(OdysseyPhysics PRIVATE /home/monsterdruide1/swsplrs/out/obj/assembled.o)
#target_sources(OdysseyPhysics PRIVATE src/test.cpp)
#add_executable(OdysseyPhysics src/tas-studio.cpp src/ui/Scene.cpp src/ui/Camera.cpp src/file/KCollision.cpp)

find_package(Threads REQUIRED)
target_link_libraries(OdysseyPhysics PRIVATE Threads::Threads)
target_link_libraries(OdysseyPhysics PUBLIC raylib)
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

add_library(swsplrs STATIC /home/monsterdruide1/swsplrs/out/obj/assembled.o)
target_link_libraries(OdysseyPhysics PUBLIC swsplrs)
set_target_properties(swsplrs PROPERTIES
    LINKER_LANGUAGE CXX
)
