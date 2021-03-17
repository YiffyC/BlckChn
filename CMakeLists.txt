# cmake_minimum_required(VERSION <specify CMake version here>)
project(BlckChn)

set(CMAKE_CXX_STANDARD 14)

add_executable(BlckChn main.cpp Block.h Blockchain.h sha256.h sha256.cpp Block.cpp Blockchain.cpp)