#!/usr/bin/env bash
#   *** validation ***
scripts/run-validator-tests.sh
scripts/run-checker-tests.sh

#    *** samples ***
echo ""
mkdir -p samples
echo "Generating answer for test #1"
scripts/gen-answer.sh samples/01 samples/01.a "samples" ""
echo ""

#    *** tests ***
mkdir -p tests
echo "Generating test #1"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1" "tests/01" 1
echo "Generating test #2"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 2" "tests/02" 2
echo "Generating test #3"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 3" "tests/03" 3
echo "Generating test #4"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 4" "tests/04" 4
echo ""
echo "Generating answer for test #1"
scripts/gen-answer.sh tests/01 tests/01.a "tests" "subtask1"
echo ""
echo "Generating answer for test #2"
scripts/gen-answer.sh tests/02 tests/02.a "tests" "subtask2"
echo ""
echo "Generating answer for test #3"
scripts/gen-answer.sh tests/03 tests/03.a "tests" "subtask3"
echo ""
echo "Generating answer for test #4"
scripts/gen-answer.sh tests/04 tests/04.a "tests" "subtask4"
echo ""

