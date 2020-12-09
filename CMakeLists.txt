cmake_minimum_required(VERSION 3.2)     

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )

project(String CXX)  
    
set(SOURCE_EXE class_string.cpp)       

set(SOURCE_LIB String.cpp String.h)            

add_library(foo STATIC ${SOURCE_LIB}) 

set_target_properties(foo PROPERTIES LINKER_LANGUAGE CXX)

add_executable(main ${SOURCE_EXE})   

target_link_libraries(main foo)       
