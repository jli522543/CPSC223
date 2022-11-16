#bin/bash

gcc -c main.c connect4.c

gcc main.o connect4.o -o main.out

chmod u+x main.out

./main.out

rm *.out
rm *.o