#!/bin/bash

echo -e "\033[32m== Building tests\033[0m"

rm -rf ./build/
mkdir -p ./build/
bash -c "cd ./build/ && cmake .."
bash -c "cd ./build/ && cmake --build ."

echo -e "\033[32m== Starting tests\033[0m"

bash -c "cd ./build/ && ctest --output-on-failure"
