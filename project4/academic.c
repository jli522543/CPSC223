
//**********************************************************************************************************************
//Program name: "Student Roster".                                                                                       *
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

//Program name: Student Roster

//Programming language: C language
//Date development begun: 2022-March-29
//Date of last update:    2022-March-31
//Developed on: WSL:Ubuntu IDE:Visual Studio Code

/*
Purpose:Creates a roster of students using data provided by user. Data of a student includes Name,Major,CWID,Class level, and zip. 
Program then sorts all student by CWID descending to ascending.
*/

//======== Begin source code ==========

#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "fillArray.h"
#include "outputArray.h"
#include "bubbleSort.h"

int main(){
    struct Student * roster[10];

    //Welcome message
    printf("Welcome to Academic Records.\n");
    printf("Please enter the data one student at a time\n\n");

    //Fills roster with data and stores number of student filled in numFilled
    int numFilled = fillarray(roster,10);

    //Prints data in roster to console
    printf("\nThank you. Here are the data you entered\n\n");
    outputarray(roster,numFilled);

    //Sorts roster by CWID
    bubblesort(roster,numFilled);
    
    //Prints sorted data to console
    printf("\nThe student data will next be sorted.\n");
    printf("The list of student data is now ordered as follows.\n");
    outputarray(roster,numFilled);
    
    
}