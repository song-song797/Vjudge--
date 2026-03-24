cmake_minimum_required(VERSION 3.20)

project(VjudgeSolutions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

file(GLOB_RECURSE CPP_SOURCES
    CONFIGURE_DEPENDS
    RELATIVE "${CMAKE_SOURCE_DIR}"
    "*.cpp"
)

list(FILTER CPP_SOURCES EXCLUDE REGEX "^build/")

if(CPP_SOURCES STREQUAL "")
    message(FATAL_ERROR "No C++ source files were found in the workspace.")
endif()

set(target_index 1)
foreach(source_file IN LISTS CPP_SOURCES)
    set(relative_source "${source_file}")
    set(absolute_source "${CMAKE_SOURCE_DIR}/${relative_source}")
    get_filename_component(source_stem "${absolute_source}" NAME_WE)
    get_filename_component(source_dir "${relative_source}" DIRECTORY)

    set(target_name "solution_${target_index}")
    add_executable("${target_name}" "${absolute_source}")
    target_compile_features("${target_name}" PRIVATE cxx_std_17)

    if(source_dir STREQUAL "")
        set(output_dir "${CMAKE_BINARY_DIR}/bin")
    else()
        set(output_dir "${CMAKE_BINARY_DIR}/bin/${source_dir}")
    endif()

    set_target_properties("${target_name}" PROPERTIES
        OUTPUT_NAME "${source_stem}"
        RUNTIME_OUTPUT_DIRECTORY "${output_dir}"
    )

    math(EXPR target_index "${target_index} + 1")
endforeach()
