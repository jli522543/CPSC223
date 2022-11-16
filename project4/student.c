#include "student.h"

#include<stdio.h>


void printStudent(struct Student* stu){
    
    //Prints name, major, and cwid
    printf("Name: %sMajor: %sCWID: %ld\nClass:",stu->name,stu->major,stu->cwid);
    
    //Switch case for enums class level
    switch(stu->level){
    case 0:
        printf("Freshman\n");
        break;
    case 1:
        printf("Sophomore\n");
        break;
    case 2:
        printf("Junior\n");
        break;
    case 3:
        printf("Senior\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }

    //Prints zip
    printf("Zip: %d\n\n",stu->zip);
}