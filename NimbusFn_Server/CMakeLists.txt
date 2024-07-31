# CMakeList.txt : CMake project for NimbusFn_Server, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (NimbusFn_Server "NimbusFn_Server.cpp" "NimbusFn_Server.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NimbusFn_Server PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
