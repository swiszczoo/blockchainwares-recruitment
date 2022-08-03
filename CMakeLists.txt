cmake_minimum_required( VERSION 3.2 )
set( PROJECT_NAME expressions )
project( ${PROJECT_NAME} )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

# Compile and set up fc library
add_subdirectory( fc )

add_executable( ${PROJECT_NAME} 
  "src/main.cpp"
)
target_include_directories( ${PROJECT_NAME} PRIVATE include )
target_link_libraries( ${PROJECT_NAME} PUBLIC fc )
