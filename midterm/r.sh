#!/bin/bash

#223C Midterm
#Name:Jackie Li Email:jli306@csu.fullerton.edu 

gcc -c -Wall -Wextra main.c copyfile.c bubblesort.c

gcc main.o copyfile.o bubblesort.o -o main.out 


chmod u+x main.out

./main.out

rm *.o
rm *.out
