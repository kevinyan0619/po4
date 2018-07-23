cmake_minimum_required(VERSION 3.10)
project(lab4)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab4 main.cpp fileReader.h fileReader.cpp IOop.h iosched.h FIFO.cpp FIFO.h SSTF.cpp SSTF.h CLOOK.cpp CLOOK.h sum_info.h FLOOK.cpp FLOOK.h LOOK.cpp LOOK.h)