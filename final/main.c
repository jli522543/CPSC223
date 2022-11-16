#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "account.h"

//File to be written to
#define file "database.bin"

void displayMenu(){
    printf("\tA: Add new student\n");
    printf("\tL: Show all students\n");
    printf("\tR: Show one student\n");
    printf("\tU: Update a student\n");
    printf("\tQ: Leave this program\n");
}

//Clears stdin buffer 
//SHOULD NOT BE USED IF STDIN BUFFER IS EMPTY!
void flushstdin(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

//Option A
void addStudent(){
    //Open file for writing
    FILE* database;
    database = fopen(file,"ab+");
    if(database == NULL){
        perror("[-]");
        exit(EXIT_FAILURE);
    }

    //Declare struct to store account info
    account acc;

    //Prompt user to enter account info
    printf("Enter student ID: ");
    scanf("%u", &acc.studentID);
    flushstdin();

    printf("Enter student name: ");
    fgets(acc.studentName,50,stdin);
    acc.studentName[strlen(acc.studentName)-1] = '\0';

    printf("Enter credit avaliable: ");
    scanf("%lf",&acc.studentGPA);
    flushstdin();

    printf("Enter amount owed: ");
    scanf("%lf",&acc.daysAbsent);
    flushstdin();

    //addStudent struct to file and close file
    int success = fwrite(&acc, sizeof(account), 1, database);
    fclose(database);

    //Check if write to file was completed
    if(success!=1){
        fprintf(stderr, "Unable to write to file");
        exit(EXIT_FAILURE);
    }
    printf("\nThe student has been written to the database\n");
}

//Option L
void printStudents(){
    //Open file for reading
    FILE* database;
    database = fopen(file,"rb+");
    if(database == NULL){
        perror("[-]");
        exit(EXIT_FAILURE);
    }
    
    //Prints out all accounts in file
    printf("The students are:\n");
    account* acc = malloc(sizeof(account));
    while(fread(acc,sizeof(account),1,database)){
        printf("%u\t%-20s\t%-10.2lf\t%.2lf\n",acc->studentID, acc->studentName, acc->studentGPA, acc->daysAbsent);
    }

    free(acc);
    fclose(database); 
}

//Option R
void findStudent(){
    //Open file for reading
    FILE* database;
    database = fopen(file,"rb");
    if(database == NULL){
        perror("[-]");
        exit(EXIT_FAILURE);
    }

    //Prompt user for position of account
    int position;
    printf("Enter position of account: ");
    scanf("%d",&position);
    flushstdin();

    //Convert position to number of bytes from beginning of file
    position = (position * sizeof(account))-sizeof(account);

    //Search account at given position in file
    account* acc = malloc(sizeof(account));
    
    //Determine size of file
    fseek(database, 0, SEEK_END);
    int fileSize = ftell(database);
    
    //Check if position is out of bounds
    if(position < fileSize){
        //Print account data at position
        fseek(database,position,SEEK_SET);
        fread(acc,sizeof(account),1,database);
        printf("%u\t%-20s\t%-10.2lf\t%.2lf\n",acc->studentID, acc->studentName, acc->studentGPA, acc->daysAbsent);
    }
    else
        printf("Sorry out of bounds. No student at that position\n");

    fclose(database);
    free(acc);
}

//Option U
void updateStudent(){
    //Open file for reading
    FILE* database;
    database = fopen(file,"rb+");
    if(database == NULL){
        perror("[-]");
        exit(EXIT_FAILURE);
    }

    //Prompt user for position of account to be updated
    int position;
    printf("What is the position of the student to be update: ");
    scanf("%d",&position);
    flushstdin();

    //Convert position to number of bytes from beginning of file
    position = (position * sizeof(account))-sizeof(account);

    //Declare struct to store account info
    account acc;

    //Determine size of file
    fseek(database, 0, SEEK_END);
    int fileSize = ftell(database);

    //Check if position is out of bounds
    if(position < fileSize){
        //Collect new data used to overwrite old data
        printf("\nEnter new data below:\n");
        printf("Enter account number: ");
        scanf("%u", &acc.studentID);
        flushstdin();

        printf("Enter student name: ");
        fgets(acc.studentName,50,stdin);
        acc.studentName[strlen(acc.studentName)-1] = '\0';

        printf("Enter credit avaliable: ");
        scanf("%lf",&acc.studentGPA);
        flushstdin();

        printf("Enter amount owed: ");
        scanf("%lf",&acc.daysAbsent);
        flushstdin();
        
        //Overwrite data at position with new data
        fseek(database,position,SEEK_SET);
        fwrite(&acc, sizeof(account), 1, database);

        //Convert position back to original number
        position = (position + sizeof(account))/sizeof(account);

        printf("\nThe student data in position %d was updated\n", position);
    }
    else{
        printf("\nSorry the desired position is out of bounds.\n");
    }
    
    fclose(database);
}

void getSelection(int selection){
    switch(selection){
        case 'A':
            addStudent();
            break;
        case 'L':
            printStudents();
            break;
        case 'R':
            findStudent();
            break;
        case 'U':
            updateStudent();
            break;
        case 'Q':
            break;
        default:
            printf("Invalid selection. Try again.\n");
            break;
    }
}

void gradebook(){
    char selection;
    bool isNotQ = true;
    
    while(isNotQ){
        //Get user selection
        printf("\nPlease enter a request: ");
        if((selection = toupper(getchar()))==EOF){//Prevents infinite loop from ctrl+d
            exit(EXIT_FAILURE);
        }
        flushstdin();

        //Determine if user selection was Q or anything else 
        if(toupper(selection) == 'Q')
            isNotQ = false;
        else
            getSelection(selection);
    }
}

int main(){

    printf("\nPlease select an option:\n");

    //Displays menu     
    displayMenu();

    //Initiate gradebook program  
    gradebook();
}