cmake_minimum_required(VERSION 3.16)
project(UnixInetDemo)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(./lib LIB_SRC)

add_executable(UnixInetDemo main.cpp ${LIB_SRC})


add_executable(TimeClient TimeClient.cpp ${LIB_SRC})
add_executable(TimeServer TimeServer.cpp ${LIB_SRC})