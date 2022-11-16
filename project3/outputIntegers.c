#include "outputIntegers.h"
#include <stdio.h>

void outputIntegers(int* matchLocations,int count){
    for(int i = 0; i<count; i++){
        printf("%d\n",matchLocations[i]);
    }
}