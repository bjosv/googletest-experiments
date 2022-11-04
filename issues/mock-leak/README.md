# Leak in Mock

Introduced v1.10 -> v1.12

## Change introducing leak (1 June 2022, release-1.12.0)
https://github.com/google/googletest/commit/0320f517fd920866d918e564105d68fd4362040a

Work around a maybe-uninitialized warning under GCC 12
Some Mock constructors insert the pointer to the Mock itself into a
global registry. Since GCC cannot see how the pointer is used (only as
an identifier), it cannot tell that the object doesn't need to be
initialized at that point at all. Work around this by using uintptr_t
instead.

## Fix 1 (28 Sep 2022)
https://github.com/google/googletest/pull/4022
CLOSED, no comments

## Fix 2 (28 Sep 2022)
https://github.com/google/googletest/pull/4023
"Fix memory leak when NiceMock is used."
StrictMocks and NiceMocks.


"We currently consider valgrind to be unsupported."
https://github.com/google/googletest/issues/3805#issuecomment-1113435843
29 April 2022
