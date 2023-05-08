CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

project(List)

add_subdirectory(../Catch2 Catch2-build)
add_executable(List-tests main_List.cpp List.cpp)
target_link_libraries(List-tests PRIVATE Catch2::Catch2)