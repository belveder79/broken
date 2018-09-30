project(minimum)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(library SHARED slib.cpp)
target_link_libraries(library pthread)
add_executable(test main.cpp)
target_link_libraries(test dl)
