cmake_minimum_required(VERSION 3.26)
project(Trie)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(Trie INTERFACE)
target_include_directories(Trie INTERFACE ${CMAKE_SOURCE_DIR}/include)

add_executable(Example examples/Example.cpp)
target_link_libraries(Example PRIVATE Trie)
