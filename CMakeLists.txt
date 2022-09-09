cmake_minimum_required(VERSION 3.14)
project(xp)

# GoogleTest requires at least C++14
#set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
  #  GIT_TAG release-1.10.0
)
FetchContent_MakeAvailable(googletest)


add_executable(test_f
  test_f.cc
)
target_link_libraries(test_f
  gtest_main
)


add_executable(test_p
  test_p.cc
)
target_link_libraries(test_p
  gtest_main
)


enable_testing()
include(GoogleTest)
gtest_discover_tests(test_f)
gtest_discover_tests(test_p)
