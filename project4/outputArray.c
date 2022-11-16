#include "student.h"

//Prints to console all students storde in stuArray
void outputarray(struct Student** stuArray,int numOfStudents){
    int currentInd = 0;
    while(currentInd<numOfStudents){
        printStudent(stuArray[currentInd++]);
    }
}