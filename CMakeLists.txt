# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("NimbusFn")

if(MSVC)
    set(CMAKE_GENERATOR_PLATFORM Win32)
    set(CMAKE_GENERATOR_PLATFORM x86)
endif()

# Include sub-projects.
add_subdirectory ("NimbusFn_Server")
