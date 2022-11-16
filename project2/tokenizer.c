//**********************************************************************************************************************
//Program name: "Tokenizer".  This program tokenizes the file given by the user and stores the tokens in a list.       *
//Copyright (C) 2022 Jackie Li                                                                                         *
//                                                                                                                     *
//This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public    *
//License version 3 as published by the Free Software Foundation.                                                      *
//This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied   *
//warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more        *
//details.  A copy of the GNU General Public License v3 is available here:  <https://www.gnu.org/licenses/>.           *
//**********************************************************************************************************************


//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2

//Author: Jackie Li
//Contact: jli306@csu.fullerton.edu

//Program name: Tokenizer

//Programming language: C language
//Date development begun: 2022-March-9
//Date of last update:    2022-March-9
//Status: The program works and will create tokens with the file and seperators given by the user.

//======== Begin source code ==========

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *textfilename=(char*)malloc(4096*sizeof(char));
    char *textfile=(char*)malloc(16384*sizeof(char));
    char *seperator=(char*)malloc(10*sizeof(char));
    
    printf("Welcome to Epic Software Systems, Inc. Head of Systeam Lab:Jackie Li\n");
    printf("Enter the name of a file to be tokanized: ");
    scanf("%s%*c", textfilename);
    //Check if input has .txt extension
    if(strcmp(".txt",&textfilename[strlen(textfilename)-4])!=0){
    printf("Not a textfile, include .txt extension\n");
    }
    else {
    FILE *myfile;
    myfile  = fopen(textfilename,"r");
    fgets(textfile,16384*sizeof(char),myfile);//Reads a line into string 
    printf("%ld characters were read from the file into an array of the program.\n",strlen(textfile));
    printf("The tokening is ready to begin.\n");
    printf("Enter the seperattor characters which may include white space and press enter:");
    
    fgets(seperator,20*sizeof(char),stdin);

    printf("Confirmation: These are the seperators =>");
    for(int i =0; i<strlen(seperator);i++){
        printf("%c",seperator[i]);
    }
    printf("\nTokenizing has finished\n");
    printf("Here is the complete list of tokens\n");
    
    //Declare data structure to be used in tokenizing algorithm
    char *token = strtok(textfile,seperator);
    int sizeoftokens = 0;
    char *tokens[20]; //Can also be declared as char** tokens

    while(token!=NULL){
        tokens[sizeoftokens++] = token;
        token = strtok(NULL,seperator);
    }   
    for(int i =0; i<sizeoftokens;i++){
        printf("Token number %d is %s\n",i,tokens[i]);
    }
    printf("Total number of tokens is %d\n",sizeoftokens);
    printf("Have a nice evening.\n");
    return 0;
    }
}