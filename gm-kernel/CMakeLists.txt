list(APPEND CMAKE_FIND_ROOT_PATH "$ENV{GCMAKE_HOME}/gcmake-build/build/install")

find_package(gcmake-build REQUIRED)

include(Im_Namen_GOTTes)

cmake_minimum_required(VERSION ${GCMAKE_CMAKE_VERSION})

project(${GCMAKE_PROJECT_NAME} VERSION ${GCMAKE_PROJECT_VERSION} DESCRIPTION ${GCMAKE_PROJECT_DESCRIPTION})

set(CMAKE_EXPORT_COMPILE_COMMANDS FALSE)
set(CMAKE_VERBOSE_MAKEFILE FALSE)

if(OWN_TEST)
    message(STATUS "OWN TEST")
    string(REPLACE "-nostdlib" "--specs=rdimon.specs" new_cmake_exe_linker_flags "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${new_cmake_exe_linker_flags}")
endif()

gcmake_add_executable(${GCMAKE_PROJECT_NAME})

if(OWN_TEST)
    target_compile_definitions(${GCMAKE_PROJECT_NAME}
        PRIVATE 
            __OWN_TEST__
    )
endif()

add_custom_command(
    TARGET
        ${GCMAKE_PROJECT_NAME}
    POST_BUILD
        COMMAND ${CMAKE_SIZE} ${GCMAKE_PROJECT_NAMESPACE}-${GCMAKE_PROJECT_NAME}
        COMMAND ${CMAKE_OBJDUMP} -d -h -p -D ${GCMAKE_PROJECT_NAMESPACE}-${GCMAKE_PROJECT_NAME} > gm-kernel.dump
        COMMAND ${CMAKE_OBJCOPY} -O binary ${GCMAKE_PROJECT_NAMESPACE}-${GCMAKE_PROJECT_NAME} gm-kernel.bin
)

include(GOTT_sei_Dank)