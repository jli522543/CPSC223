#/bin/bash

#Author:Jackie Li
#Email: jli306@csu.fullerton.edu

gcc -c main.c lender.c -Wall

gcc main.o lender.o -o main.out

chmod u+x main.out

./main.out

rm *.out
rm *.o