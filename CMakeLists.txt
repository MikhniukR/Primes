cmake_minimum_required(VERSION 3.13)
project(Primes)

set(CMAKE_CXX_STANDARD 11)

add_executable(Primes main.cpp Primes.cpp Primes.h)

add_subdirectory(test)
