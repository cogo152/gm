get_filename_component(current_path ${CMAKE_SOURCE_DIR} PATH)
cmake_path(GET current_path PARENT_PATH parent_path)

list(APPEND CMAKE_FIND_ROOT_PATH "${parent_path}/gcmake/gcmake-build/build/install")

find_package(gcmake-build REQUIRED)

include(Im_Namen_GOTTes)

cmake_minimum_required(VERSION ${GCMAKE_CMAKE_VERSION})

project(${GCMAKE_PROJECT_NAME} VERSION ${GCMAKE_PROJECT_VERSION} DESCRIPTION ${GCMAKE_PROJECT_DESCRIPTION})

if(QEMU)
    message(STATUS "Building for QEMU")
    string(REPLACE "-nostdlib" "--specs=nano.specs --specs=rdimon.specs" new_cmake_exe_linker_flags "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${new_cmake_exe_linker_flags}")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS FALSE)
set(CMAKE_VERBOSE_MAKEFILE FALSE)

gcmake_add_executable(${GCMAKE_PROJECT_NAME})

target_include_directories(${GCMAKE_PROJECT_NAME}
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/include/Inc
)

add_custom_command(
    TARGET
        ${GCMAKE_PROJECT_NAME}
    POST_BUILD
        COMMAND ${CMAKE_SIZE} ${GCMAKE_PROJECT_NAMESPACE}-${GCMAKE_PROJECT_NAME}
        COMMAND ${CMAKE_OBJDUMP} -S --disassemble ${GCMAKE_PROJECT_NAMESPACE}-${GCMAKE_PROJECT_NAME} > gm-kernel.list
        COMMAND ${CMAKE_OBJCOPY} -O ihex ${GCMAKE_PROJECT_NAMESPACE}-${GCMAKE_PROJECT_NAME} gm-kernel.hex
        COMMAND ${CMAKE_OBJCOPY} -O srec --srec-len 0x10 ${GCMAKE_PROJECT_NAMESPACE}-${GCMAKE_PROJECT_NAME} gm-kernel.srec
        COMMAND ${CMAKE_OBJCOPY} -O binary ${GCMAKE_PROJECT_NAMESPACE}-${GCMAKE_PROJECT_NAME} gm-kernel.bin
)

include(GOTT_sei_Dank)