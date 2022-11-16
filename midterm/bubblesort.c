//223C Midterm
//Name:Jackie Li Email:jli306@csu.fullerton.edu

#include <stdio.h>
#include <string.h>
//Swapping algorithm
void swap(char**str1,char**str2)
{
    char * temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

//Sort Algorithm
void bubblesort(char**arr, int numOfLines){
    int i, j;
    for (i = 0; i < numOfLines-1; i++)	
	    for (j = 0; j < numOfLines-i-1; j++)
		    if (strcmp(arr[j],arr[j+1])>0) 
			    swap(&arr[j],&arr[j+1]);
}







