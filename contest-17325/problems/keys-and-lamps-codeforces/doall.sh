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
scripts/gen-input-via-stdout.sh "wine files/genAll.exe" "tests/01" 1
echo ""
echo "Generating answer for test #1"
scripts/gen-answer.sh tests/01 tests/01.a "tests" ""
echo ""

