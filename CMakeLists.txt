cmake_minimum_required(VERSION 3.25)

project(ParafusersEngine
    VERSION 0.1.0
    DESCRIPTION "Parafusers Engine: engine de jogos 2D e 3D"
    LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

option(PARAFUSERS_BUILD_SANDBOX "Compila o sandbox de testes" ON)
option(PARAFUSERS_BUILD_EDITOR "Compila o editor (ainda vazio)" ON)

include(cmake/CompilerWarnings.cmake)

add_subdirectory(engine)

if(PARAFUSERS_BUILD_SANDBOX)
    add_subdirectory(sandbox)
endif()

if(PARAFUSERS_BUILD_EDITOR)
    add_subdirectory(editor)
endif()
