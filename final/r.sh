#!/bin/bash

#223C Final
#Name:Jackie Li Email:jli306@csu.fullerton.edu 

gcc -c -Wall -Wextra main.c 

gcc main.o -o main.out 


chmod u+x main.out

./main.out

rm *.o
rm *.out
