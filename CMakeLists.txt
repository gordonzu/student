project(Student2)
cmake_minimum_required(VERSION 2.6)

include_directories("$ENV{GMOCK_HOME}/include" "$ENV{GMOCK_HOME}/gtest/include" 
                    "$ENV{HOME}/src/cpp/accel") 
link_directories("$ENV{GMOCK_HOME}/mybuild" "$ENV{GMOCK_HOME}/gtest/mybuild")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -O0")

set(sources
    Student2Test.cpp
    main.cpp
  )

add_executable(student2 ${sources})
target_link_libraries(student2 gmock)
target_link_libraries(student2 gtest)
target_link_libraries(student2 pthread)

add_custom_command(TARGET student2 
                 POST_BUILD
                 COMMAND "make")

add_custom_command(TARGET student2
                 POST_BUILD
#                COMMAND valgrind --tool=memcheck --leak-check=yes ./xyenv)
                 COMMAND "student2")

