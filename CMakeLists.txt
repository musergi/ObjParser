cmake_minimum_required(VERSION 3.9)
project(ObjParser VERSION 1.0)
add_library(ObjParser SHARED
    src/obj_content.cpp
    src/line_bufferer.cpp
    src/obj_line_buffer_processor.cpp
    src/vertex_data/geometric_vertex.cpp
    src/vertex_data/texture_vertex.cpp
    src/vertex_data/vertex_normal.cpp
    src/elements/face.cpp
    src/elements/vertex_reference.cpp
)
target_include_directories(ObjParser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# add tests
add_subdirectory(tests)
