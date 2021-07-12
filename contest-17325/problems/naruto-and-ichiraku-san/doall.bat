rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** samples ***
md samples
call scripts\gen-answer.bat samples\01 samples\01.a "samples" ""

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen.exe 1" "tests\01" 1
call scripts\gen-input-via-stdout.bat "files\gen.exe 2" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\gen.exe 3" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\gen.exe 4" "tests\06" 6
call scripts\gen-answer.bat tests\01 tests\01.a "tests" "subtask1"
call scripts\gen-answer.bat tests\02 tests\02.a "tests" "subtask2"
call scripts\gen-answer.bat tests\03 tests\03.a "tests" "subtask2"
call scripts\gen-answer.bat tests\04 tests\04.a "tests" "subtask3"
call scripts\gen-answer.bat tests\05 tests\05.a "tests" "subtask3"
call scripts\gen-answer.bat tests\06 tests\06.a "tests" "subtask4"
call scripts\gen-answer.bat tests\07 tests\07.a "tests" "subtask4"

