#!/bin/bash

#Author: J. Li
#Author email: jli306@csu.fullerton.edu

#Program name: Tokanizer

#Delete some un-needed files

echo "Compile tokenizer.c"
gcc -c -Wall tokenizer.c 

echo "Link the object files"
gcc tokenizer.o -o tokenizer.out 

#Make sure the executable has permission to execute
chmod u+x tokenizer.out

echo "Run the program"
./tokenizer.out

echo "Removing object and executable files"
rm *.o
rm *.out

echo "The progam will terminate"
