# googletest experiments

## Set googletest version
Change `GIT_TAG` in `FetchContent_Declare` in `CMakeLists.txt`

release-1.10.0 will require a fix:
Default set variable `dummy` in: gtest-death-test.cc:1301:24

## Build
```
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S . -B build
cmake --build build

# Change and rebuild googletest only
cd build
edit code in _deps/googletest-src/googletest/..
make -C _deps/googletest-build
make

# Build googletest manually
mkdir mybuild && cd mybuild
cmake -Dgtest_build_tests=ON -Dgmock_build_tests=ON ..
make

# Run clang-format on changes:
clang-format -i --style=file <file>
```

## Get Clang Tidy
```
sudo apt update
apt search clang-tidy
sudo apt install clang-tidy
```

# Check TEST_F
```
clang-tidy -system-headers -checks='-*,cppcoreguidelines-special-member-functions' -p=build test_f.cc
clang-tidy -system-headers -checks='-*,cppcoreguidelines-avoid-non-const-global-variables' -p=build test_f.cc
```

# Check TEST_P
```
clang-tidy -system-headers -checks='-*,cppcoreguidelines-special-member-functions' -p=build test_p.cc
clang-tidy -system-headers -checks='-*,cppcoreguidelines-avoid-non-const-global-variables' -p=build test_p.cc
```

# Other

## Correction of `rule of 5` in TEST_F
https://github.com/google/googletest/commit/fbe34cecf4ff34e0bed76aefb2b4d31f7b1f6819

## Correction of default in TEST_F constructor
https://github.com/google/googletest/pull/2952
fix clang tidy modernize-use-equals-default warnings
git show 7bde252cb

## Google C++ Style Guide
* A class's public API must make clear whether the class is copyable, move-only, or neither copyable nor movable.
  Support copying and/or moving if these operations are clear and meaningful for your type.

https://google.github.io/styleguide/cppguide.html#Copyable_Movable_Types

## C++ Core Guidelines
### C.21: If you define or =delete any copy, move, or destructor function, define or =delete them all
https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c21-if-you-define-or-delete-any-copy-move-or-destructor-function-define-or-delete-them-all

## C++ Core Guidelines: The Rule of Zero, Five, or Six
https://www.modernescpp.com/index.php/c-core-guidelines-constructors-assignments-and-desctructors
