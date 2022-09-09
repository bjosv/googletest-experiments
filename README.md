# googletest experiments

## Set googletest version
Change `GIT_TAG` in `FetchContent_Declare` in `CMakeLists.txt`

release-1.10.0 will require a fix:
Default set variable `dummy` in: gtest-death-test.cc:1301:24

## Build
```
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S . -B build
cmake --build build
```

# Check TEST_F
```
clang-tidy -system-headers -checks='-*,cppcoreguidelines-special-member-functions' -p=build test_f.cc
```

# Check TEST_P
```
clang-tidy -system-headers -checks='-*,cppcoreguidelines-special-member-functions' -p=build test_p.cc
```
