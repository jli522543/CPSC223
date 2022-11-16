#include "student.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Flushes data out of input, used to clear newline character left by scanf()
void flushstdin(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int fillarray(struct Student ** stuArray,int size){
    int currentInd =0;
    char ch;

    do{//Collects data from input to fill a Student struct
    
    //Allocates memmory for current struct student pointer
    stuArray[currentInd] = (struct Student*)malloc(sizeof(struct Student));

    //Begin collecting data
    printf("Name: ");
    fgets(stuArray[currentInd]->name,50,stdin);
    //scanf("%s",stuArray[currentInd]->name);

    printf("Major: ");
    fgets(stuArray[currentInd]->major,50,stdin);
    //scanf("%s",stuArray[currentInd]->major);
    
    printf("CWID: ");
    scanf("%ld",&stuArray[currentInd]->cwid);
    flushstdin();

    printf("Class level (fresh=0,soph=1,junior=2,senior=3): ");
    scanf("%ud",&stuArray[currentInd]->level);
    flushstdin();

    printf("Zip: ");
    scanf("%d",&stuArray[currentInd]->zip);
    flushstdin();

    //Prompts user if they wish to continue adding more data
    printf ("\nDo you have more data(y/n)?");
    scanf ("%c", &ch);
    flushstdin();
    currentInd++;

    } while(ch == 'y' && currentInd<size); //Contniues as long as user inputs 'y' and currentInd does not exceed size of array
    return currentInd;
}