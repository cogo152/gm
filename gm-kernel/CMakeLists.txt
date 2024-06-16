list(APPEND CMAKE_FIND_ROOT_PATH "$ENV{GCMAKE_HOME}/gcmake-build/build/install")

find_package(gcmake-build REQUIRED)

include(Im_Namen_GOTTes)

cmake_minimum_required(VERSION ${GCMAKE_CMAKE_VERSION})

project(${GCMAKE_PROJECT_NAME} VERSION ${GCMAKE_PROJECT_VERSION} DESCRIPTION ${GCMAKE_PROJECT_DESCRIPTION})

set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
set(CMAKE_VERBOSE_MAKEFILE OFF)

if(TEST)
    message(STATUS "TEST USING SEMIHOST")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --specs=rdimon.specs")
    add_compile_definitions(SEMIHOST)
endif()

gcmake_add_library(${GCMAKE_PROJECT_NAME} INTERFACE)

gcmake_add_test(${GCMAKE_PROJECT_NAME}_test
    PRIVATE
        ${GCMAKE_PROJECT_NAME}
)

add_custom_command(
    TARGET
        ${GCMAKE_PROJECT_NAME}_test
    POST_BUILD
        COMMAND ${CMAKE_SIZE} ${GCMAKE_PROJECT_NAMESPACE}-${GCMAKE_PROJECT_NAME}_test
        COMMAND ${CMAKE_OBJDUMP} -d -h -p -D ${GCMAKE_PROJECT_NAMESPACE}-${GCMAKE_PROJECT_NAME}_test > gm-kernel_test.dump
        COMMAND ${CMAKE_OBJCOPY} -O binary ${GCMAKE_PROJECT_NAMESPACE}-${GCMAKE_PROJECT_NAME}_test gm-kernel_test.bin
)

include(GOTT_sei_Dank)