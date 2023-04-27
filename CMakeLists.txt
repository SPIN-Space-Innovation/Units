# MIT License
# 
# Copyright (c) 2023 SPIN - Space Innovation
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 3.10)
project(SPIN-Units VERSION 0.1.0)

set(CXX_STANDARD 23)

include_directories("${CMAKE_CURRENT_LIST_DIR}/include/public")
include_directories("${CMAKE_CURRENT_LIST_DIR}/include/private")

include("${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt")

add_library("SPIN-Units_shared" SHARED ${SRC_CXX};${SRC_C})
add_library("SPIN-Units_static" STATIC ${SRC_CXX};${SRC_C})

if (NOT WIN32)
    set_target_properties("SPIN-Units_shared" PROPERTIES OUTPUT_NAME SPIN-Units)
    set_target_properties("SPIN-Units_static" PROPERTIES OUTPUT_NAME SPIN-Units)
endif()

target_include_directories("SPIN-Units_shared" PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include/public")
target_include_directories("SPIN-Units_static" PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include/public")

install (TARGETS "SPIN-Units_shared"
         ARCHIVE DESTINATION lib
         LIBRARY DESTINATION lib)

install (TARGETS "SPIN-Units_static"
         ARCHIVE DESTINATION lib
         LIBRARY DESTINATION lib)

install(DIRECTORY "${CMAKE_SOURCE_DIR}/include/public/"
        DESTINATION "include"
        FILES_MATCHING
        PATTERN "*.hpp")

install(DIRECTORY "${CMAKE_SOURCE_DIR}/include/public/"
        DESTINATION "include"
        FILES_MATCHING
        PATTERN "*.h")
