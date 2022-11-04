cmake_minimum_required(VERSION 3.14)
project(xp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use sanitizers, build with clang:
# CXX=clang++ CC=clang cmake ..
# add_compile_options(-fsanitize=memory)
# add_link_options(-fsanitize=memory)
# add_compile_options(-fsanitize=address)
# add_link_options(-fsanitize=address)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git

  # Official
  GIT_TAG release-1.12.1
  # GIT_TAG release-1.12.0
  # GIT_TAG release-1.11.0
  # GIT_TAG release-1.10.0

  #GIT_TAG e23cdb78e9fef1f69a9ef917f447add5638daf2a # Before fix
  #GIT_TAG 93f08be653c36ddc6943e9513fc14c7292b4d007 # With fix

  # Nordix
  # GIT_REPOSITORY https://github.com/Nordix/googletest.git
  # GIT_TAG 385bd4fba0fbbd524026c5cdc8a3618d6e65ec56
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


add_executable(mock
  mock.cc
)
target_link_libraries(mock
  gmock gtest_main
)


# enable_testing()
# include(GoogleTest)
# gtest_discover_tests(test_f)
# gtest_discover_tests(test_p)
# gtest_discover_tests(mock)
