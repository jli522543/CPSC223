#include <stdio.h>
#include "student.h"

//Swapping algorithm
void swap(struct Student **stu1, struct Student **stu2)
{
	struct Student *temp = *stu1;
	*stu1 = *stu2;
	*stu2 = temp;
}

//Sort Algorithm
void bubblesort(struct Student** studentArray, int numOfStudents){
    int i, j;
    for (i = 0; i < numOfStudents-1; i++)	
	    for (j = 0; j < numOfStudents-i-1; j++)
		    if (studentArray[j]->cwid > studentArray[j+1]->cwid)
			    swap(&studentArray[j],&studentArray[j+1]);
}







