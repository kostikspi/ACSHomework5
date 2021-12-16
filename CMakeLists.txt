cmake_minimum_required(VERSION 3.20)
project(ACSHomework5)

set(CMAKE_CXX_STANDARD 20)
find_package(Threads REQUIRED)

add_executable(ACSHomework5 main.cpp cashier.cpp cashier.h customer.cpp customer.h queue.cpp queue.h)
target_link_libraries(ACSHomework5 PRIVATE Threads::Threads)
