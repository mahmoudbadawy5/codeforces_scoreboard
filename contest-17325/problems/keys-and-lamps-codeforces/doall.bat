rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** samples ***
md samples
call scripts\gen-answer.bat samples\01 samples\01.a "samples" ""

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\genAll.exe" "tests\01" 1
call scripts\gen-answer.bat tests\01 tests\01.a "tests" ""

