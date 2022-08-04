cmake_minimum_required( VERSION 3.2 )
set( PROJECT_NAME expressions )
project( ${PROJECT_NAME} )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

# Compile and set up fc library
add_subdirectory( fc )

add_executable( ${PROJECT_NAME} 
  "src/main.cpp"
  "src/abstract_expressions.cpp"
  "src/abstract_visitor.cpp"
  "src/static_expressions.cpp"
  "src/static_visitor.cpp"
)
target_include_directories( ${PROJECT_NAME} PRIVATE include )
target_link_libraries( ${PROJECT_NAME} PUBLIC fc )

# unit tests

include( CTest )
if( BUILD_TESTING )

add_subdirectory( googletest )
set( TESTS_NAME expressions_tests )

add_executable( ${TESTS_NAME} 
  "src/abstract_expressions.cpp"
  "src/abstract_visitor.cpp"
  "src/static_expressions.cpp"
  "src/static_visitor.cpp"

  "tests/expressions.cpp"
  "tests/visitors.cpp"
)

target_include_directories( ${TESTS_NAME} PRIVATE include )
target_link_libraries( ${TESTS_NAME} PUBLIC gtest )
target_link_libraries( ${TESTS_NAME} PUBLIC gtest_main )
target_link_libraries( ${TESTS_NAME} PUBLIC fc )

add_test(NAME unit COMMAND ${TESTS_NAME})

endif()
