cmake_minimum_required(VERSION 3.10)
project(The-crawler)
add_subdirectory(inc)
add_executable(The-crawler ${PROJECT_SOURCE_DIR}/src/Main.cpp)
target_link_libraries(The-crawler ncurses Game)
