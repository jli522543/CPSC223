//**********************************************************************************************************************
//Program name: "String Search".                                                                                       *
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

//Program name: String Searched

//Programming language: C language
//Date development begun: 2022-March-9
//Date of last update:    2022-March-9
//Developed on: WSL:Ubuntu IDE:Visual Studio Code

/*
Purpose:User inputs file name and a key to be searched within file. Program returns an
array of integers containing the position where each occurence of the key was found
*/

//======== Begin source code ==========
 
#include "copyFile.h"
#include "outputIntegers.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
   
    char* filename = (char*)malloc(1024*sizeof(char));
    char* searchArray = (char*)malloc(4096*sizeof(char));
    char* searchKey =(char*)malloc(512*sizeof(char));
    
    //Welcome statements
    printf("Welcome to Find Your Match produced by Orange Blossom Lucky Software,Inc.\n"
    "Project Leader:Jackie Li\n"
    "This program will find the matching strings in any text file\n");
    
    //Prompts user for file name. File name will be printed to console
    printf("Please enter the name of the file to be searched:");
    scanf("%s",filename);
    
    //Copies file into array.
    int success = copyfile(filename,searchArray,4096);

    //Checks if file is empty or could not opened
    if(success==0){
        printf("Error in retrieving file\n");
    }
    else{
    
    //Prompts user for key to be searched. Key will be printed to console
    printf("Please enter the search pattern you are seeking:");
    scanf("%s",searchKey);
    printf("Thank you. You entered %s\n",searchKey);

    //Declare data structure needed for seach algorithm
    int* location = (int*)malloc(1024*sizeof(int));
    int currentInd = 0;
    char* ptr;
    char* searchArrayCopy =searchArray;
    
    //Search Alogrithm
    while((ptr = strstr(searchArrayCopy,searchKey))!=NULL){
       location[currentInd++] = ptr - searchArray;
       searchArrayCopy = ptr + 1;
    }
    
    //Shows the indices where key was found in the file
    printf("The search has been completed. The search key %s is found in these " 
    "positions within the file:\n",searchKey);
    outputIntegers(location,currentInd);
    return 0;
    }
}