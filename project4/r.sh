#!/bin/bash

#Author: J. Li
#Author email: jli306@csu.fullerton.edu

#Program name: Students roster

gcc -c -Wall -m64 academic.c fillArray.c outputArray.c student.c bubbleSort.c -std=c17

gcc academic.o fillArray.o student.o outputArray.o bubbleSort.o -o academic.out -std=c17

chmod u+x academic.out

./academic.out

rm *.out
rm *.o