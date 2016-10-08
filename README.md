# PlatformIO sample project with unity tests
This is sample project for understanding that how to run tests and how `platformio test` command works.

## Build for target release and host test
- This sample has 2 environments.
  - `uno` for target environment **without tests**
  - `local` for host environment **with tests**
- Default environment is set as `uno`, so building normally makes only for `uno` binary.
  - If you want to build other targets usually, add env names to `env_default` in `platformio.ini`.

## How platformio tests works
- A directory under `test` directory works as a Test Group.
- Each directory has a main function.
- Each RUN_TEST() in main function works as a Test.
- There are no `unity_fixture.h`, so `TEST()`, `TEST_GROUP()`, `TEST_GROUP_RUNNER()` are not available.
  - Platformio collects Test Groups under `test` directory automatically.
  - Therefore don't have to run Test Groups manually using `RUN_TEST_GROUP()`.
- `void setUp(void)` and `void tearDown(void)` work as setup and teardown function.
  - `setUp`/`tearDown` run before/after each RUN_TEST().
  - `setUp`/`tearDown` are not required.

## How to run tests
- Run `platformio test -e local` in platformio terminal.

## Sample output
- Sample tests
  - Test group `foo`: 2 tests which should pass.
  - Test group `bar`: 1 test which should fail.

```
PlatformIO Plus (http://pioplus.com) v0.1.0
Verbose mode can be enabled via `-v, --verbose` option
Collected 2 items

================================================================================== [test::bar] Building... (1/2) ==================================================================================

[Sat Oct  8 17:30:34 2016] Processing local (platform: native, piotest: bar)
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Please wait...

============================================================================================ [SUMMARY] ============================================================================================
Environment local	[SUCCESS]
Environment uno	[SKIP]
=================================================================================== [SUCCESS] Took 0.59 seconds ===================================================================================

=================================================================================== [test::bar] Testing... (2/2) ===================================================================================
test/bar/test_bar.cpp:7:test_bar:FAIL: Expected 1 Was 2	[FAILED]

-----------------------
1 Tests 1 Failures 0 Ignored
FAIL

================================================================================== [test::foo] Building... (1/2) ==================================================================================

[Sat Oct  8 17:30:34 2016] Processing local (platform: native, piotest: foo)
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Please wait...

============================================================================================ [SUMMARY] ============================================================================================
Environment local	[SUCCESS]
Environment uno	[SKIP]
=================================================================================== [SUCCESS] Took 0.55 seconds ===================================================================================

=================================================================================== [test::foo] Testing... (2/2) ===================================================================================
Setup: counter=1.  Tear down: counter=2.  test/foo/test_foo.cpp:39:test_foo1	[PASSED]
Setup: counter=1.  Tear down: counter=2.  test/foo/test_foo.cpp:40:test_foo2	[PASSED]

-----------------------
2 Tests 0 Failures 0 Ignored
OK

========================================================================================== [TEST SUMMARY] ==========================================================================================
test:bar/env:local	[FAILED]
test:foo/env:local	[PASSED]
==================================================================================== [FAILED] Took 1.17 seconds ====================================================================================
```
