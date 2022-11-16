//223C Midterm
//Name:Jackie Li Email:jli306@csu.fullerton.edu 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "copyfile.h"
#include "bubblesort.h"


int main(){
    
    //Level Blank
    printf("BLANK LEVEL\n");
    char *  message = "Congratulations\nDr.Jo.\n";
    for(int i = 0; i<12;i++){
        printf("%s",message);
    }
    printf("Goodbye Dr.Jo.\n");

    //Level Beginner
    char* filename = (char*)malloc(1024*sizeof(char));
    char* content = (char*)malloc(4096*sizeof(char));
    
    //Prompts user for filename
    printf("\nBEGINNER LEVEL\n");
    printf("Please enter the name of the file to be searched:");
    scanf("%s",filename);

    //Copyfile to array
    int success = copyfile(filename,content,4096);
    
    //Check if copy was successful
    if(success==0){
        printf("Error in retrieving file\n");
    }
    else{
        //File was read one char at at time so newchar was also read in
        printf("\nThe content of the file is:\n%s",content);
        printf("\nNumber of chars read and placed into array was %d\n",success);
    }

    //Level Academic
    printf("\nACADEMIC LEVEL\n");

    //Delcare twoDimArray with static 100 rows
    char * twoDimArray[100];
    
    //Each physical line is split with a newline char
    //Seperator is newline char
    char * seperator = "\n"; 
    char *token = strtok(content,seperator);
    int sizeofarray = 0;
    
    while(token!=NULL){
        twoDimArray[sizeofarray++] = token;
        token = strtok(NULL,seperator);
    }   

    //Print 2d array
    printf("Contents of 2d array:\n");
    for(int i =0; i<sizeofarray;i++){
        printf("%s\n",twoDimArray[i]);
    }

    //Level Universe
    printf("\nUNIVERSE LEVEL\n");
   
    //Sort 2D array alphabetically
    bubblesort(twoDimArray,sizeofarray);
    
    //Print 2d array after being sorted
    printf("2d array after being sorted:\n");
    for(int i =0; i<sizeofarray;i++){
        printf("%s\n",twoDimArray[i]);
    }
   
    printf("\nNew 1d array\n%s",content);

}