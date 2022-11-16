#include "copyFile.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int copyfile(char* filename,char* searchstring,int max){
    FILE* myfile = fopen(filename,"r");
    int charcount = 0;
    int onebyte;
    
    //Check if file exists
    if(myfile==NULL)
        charcount = 0;
    else{//Reads file into searchstring array 
        while((onebyte=fgetc(myfile))!=EOF && charcount<max){
        searchstring[charcount++] = onebyte;
        }
        fclose(myfile);
    }
    

    //Returns count of chars read into file. Returns zero if empty or file could not be opened
    return charcount;
    
}   