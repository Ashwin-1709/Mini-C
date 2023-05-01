#!/bin/env bash
cd lexical_analysis || exit 1
./compile.sh
cd ..
cd syntax_analysis || exit 1
./compile.sh
cd ..
cd semantic_analysis || exit 1
./compile.sh
cd ..
cd intermediate_code || exit 1
./compile.sh
cd ..
cd simulation || exit 1
./compile.sh
