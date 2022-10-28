# cppcoreguidelines-avoid-non-const-global-variables

https://releases.llvm.org/11.0.0/tools/clang/tools/extra/docs/clang-tidy/checks/cppcoreguidelines-avoid-non-const-global-variables.html

```
> clang-tidy -system-headers -checks='-*,cppcoreguidelines-avoid-non-const-global-variables' -p=build test_f.cc

148 warnings generated.
----------------------------------------------
.../test_f.cc:7:1: warning: variable 'test_info_' provides global access to a non-const object; consider making the pointed-to data 'const' [cppcoreguidelines-avoid-non-const-global-variables]
TEST_F(TestF, checkZero)
^
.../googletest/include/gtest/gtest.h:2200:41: note: expanded from macro 'TEST_F'
#define TEST_F(test_fixture, test_name) GTEST_TEST_F(test_fixture, test_name)
                                        ^
.../googletest/include/gtest/gtest.h:2197:3: note: expanded from macro 'GTEST_TEST_F'
  GTEST_TEST_(test_fixture, test_name, test_fixture, \
  ^
.../googletest/include/gtest/internal/gtest-internal.h:1554:39: note: expanded from macro 'GTEST_TEST_'
    static ::testing::TestInfo* const test_info_ GTEST_ATTRIBUTE_UNUSED_;      \
                                      ^
----------------------------------------------
Suppressed 146 warnings (146 in non-user code).
Use -header-filter=.* to display errors from all non-system headers. Use -system-headers to display errors from system headers as well.
```

## Details
`#define GTEST_ATTRIBUTE_UNUSED_ __attribute__((unused))`

Change:
`static ::testing::TestInfo* const test_info_;`
> const pointer to ::testing::TestInfo

to:
`static const ::testing::TestInfo* const test_info_;`
> const pointer to const ::testing::TestInfo


## CppCoreGuidelines issues
https://github.com/isocpp/CppCoreGuidelines/issues/1599

## LLVM issues
### Check added
https://reviews.llvm.org/D70265
### Correction
https://reviews.llvm.org/D100972

https://bugs.llvm.org/show_bug.cgi?id=48040


# Other
https://rules.sonarsource.com/cpp/RSPEC-5421
