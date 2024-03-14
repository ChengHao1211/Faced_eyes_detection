cmake_minimum_required(VERSION 3.5.0)
project(OPENCVEXAMPLE VERSION 0.1.0)

include(CTest)
enable_testing()

find_package( OpenCV REQUIRED )
include_directories( ${Opencv_INCLUDE_DIRS} )

add_executable(OPENCVEXAMPLE main.cpp)

target_link_libraries( OPENCVEXAMPLE ${OpenCV_LIBS} )

set(CPACK_PROJECTNMAE ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)