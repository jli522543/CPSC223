#ifndef STUDENT_H
#define STUDENT_H


#include<stdio.h>

enum standing{Freshman,Sophmore,Junior,Senior};

struct Student{
    char name[50];
    long int cwid;
    char major[50];
    enum standing level;
    int zip;
};

//Output data of one student 
void printStudent(struct Student* stu);
#endif

