#!/bin/bash

#Author: J. Li
#Author email: jli306@csu.fullerton.edu

#Program name: String Search

echo "Compile tokenizer.c"
gcc -c -Wall -Wextra -m64 -no-pie search.c copyFile.c outputIntegers.c -std=c17

echo "Link the object files"
gcc copyFile.o search.o outputIntegers.o -o search.out -std=c17

#Make sure the executable has permission to execute
chmod u+x search.out

echo "Run the program"
./search.out

#Delete some un-needed files
echo "Removing object and executable files"
rm *.o
rm *.out


echo "The progam will terminate"
