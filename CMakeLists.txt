cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(gl_play)

find_package(Boost REQUIRED COMPONENTS filesystem)

set(LIB_HEADER_FILES
    include/glad/glad.h
    include/KHR/khrplatform.h
    include/shader.h
    include/stb_image.h
    )

set(LIB_SOURCE_FILES
    src/glad.cpp
    src/shader.cpp
    )



add_library(musa_gl_libs
    SHARED
    ${LIB_SOURCE_FILES}
    ${LIB_HEADER_FILES}
    )

target_include_directories(musa_gl_libs PRIVATE include)

set_target_properties(musa_gl_libs
    PROPERTIES
    CXX_STANDARD 11
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE 1

    )

target_link_libraries(musa_gl_libs ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} GLU GLEW glfw )


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)


set(SOURCE_FILES
    src/main.cpp
    src/window.cpp
    src/entity.cpp
    src/cube.cpp
    src/world_loader.cpp
    src/file_world_loader.cpp
    src/perlin_world_loader.cpp
    src/mesh_factory.cpp
    src/texture_factory.cpp
    )

add_executable(gl_play  ${SOURCE_FILES})



include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS}
    include
    )


target_link_libraries(gl_play  musa_gl_libs)
