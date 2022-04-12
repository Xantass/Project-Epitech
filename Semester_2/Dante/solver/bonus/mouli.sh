#!/bin/bash

x=$(($RANDOM % 100))
y=$(($RANDOM % 100))

../../generator/generator y x > ../maze.txt
../solver ../maze.txt > res
rm ../maze.txt
cat res | grep "no solution found"
if [ $? == 0 ]; then
    echo -e "\e[31mNo solution found\e[0m"
else
    echo -e "\e[32mSolution found !!\e[0m"
    cat res
fi
rm res
