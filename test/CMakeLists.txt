cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 11)

set(REPO ~/Projects/C++/Primes/.repo)

project(Test)

project(Example)

include(CTest)
enable_testing()

#set(gtest_disable_pthreads on) #needed in MinGW
include(${REPO}/DownloadProject/DownloadProject.cmake)
download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)

#set(test_SRCS ADD ALL TEST SOURCE FILES HERE)
add_executable(runUnitTests PrimesTest.cpp ${test_SRCS})
target_link_libraries(runUnitTests gtest gmock core)
#add_test(runUnitTests runUnitTests) #included in all tutorials but I don't know what
