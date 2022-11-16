#/bin/bash

#Project 5
#Name:Jackie Li Email:jli306@csu.fullerton.edu

gcc -c main.c store.c purchaseItem.c -Wall

gcc main.o store.o purchaseItem.o -o  main.out

chmod u+x main.out

./main.out

rm *.out
rm *.o