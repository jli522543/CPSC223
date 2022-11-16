#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "account.h"
#include "lender.h"

void findAccount(){
    //Open file for reading
    FILE* database;
    database = fopen(file,"rb+");
    if(database == NULL){
        perror("[-]");
        exit(EXIT_FAILURE);
    }

    //Prompt user for position of account
    int position;
    printf("Enter position of account: ");
    scanf("%d",&position);
    flushstdin();
    position = (position * sizeof(account))-sizeof(account);

    //Search account at given position in file
    account* acc = malloc(sizeof(account));
    if(fseek(database,position,SEEK_SET)==0){
        fread(acc,sizeof(account),1,database);
        printf("%u\t%-20s\t%-10.2lf\t%.2lf\n",acc->accountNumber, acc->customerName, acc->creditAvaliable, acc->balanceDue);
    }
    else
        printf("Sorry not found");

    fclose(database);
    free(acc);
}

void findPosition(){
     //Open file for reading
    FILE* database;
    database = fopen(file,"rb+");
    if(database == NULL){
        perror("[-]");
        exit(EXIT_FAILURE);
    }
    
    //Prompt user for account number to be found
    int accNumber;
    printf("Enter Account Number: ");
    scanf("%d",&accNumber);
    flushstdin();

    //Find account number in file 
    bool success = false;
    int position = 1;
    account* acc = malloc(sizeof(account));
    
    while(fread(acc,sizeof(account),1,database)==1 && !success){
        if(acc->accountNumber == accNumber){
            success = true;
            break;
        }
        position++;
    }
    free(acc);
    fclose(database);

    //Print position of account number if account was found in file
    if(success){
        printf("\nAccount number %d is located at position %d.\n",accNumber,position);
    }
    else
        printf("\nAccount number %d could not be found.\n",accNumber);

}

void lender(){
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

void append(){
    
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
    printf("Enter account number: ");
    scanf("%u", &acc.accountNumber);
    flushstdin();

    printf("Enter customer name: ");
    fgets(acc.customerName,50,stdin);
    acc.customerName[strlen(acc.customerName)-1] = '\0';

    printf("Enter credit avaliable: ");
    scanf("%lf",&acc.creditAvaliable);
    flushstdin();

    printf("Enter balance due: ");
    scanf("%lf",&acc.balanceDue);
    flushstdin();

    //Append struct to file and close file
    int success = fwrite(&acc, sizeof(account), 1, database);
    fclose(database);

    //Check if write to file was c
    if(success!=1){
        fprintf(stderr, "Unable to write to file");
        exit(EXIT_FAILURE);
    }
    printf("\nThe customer has been written to Sunflower database\n");
}

void printNumberofAccounts(){
    //Open file for reading
    FILE* database;
    database = fopen(file,"rb+");
    if(database == NULL){
        perror("[-]");
        exit(EXIT_FAILURE);
    }
    
    //Prints out all accounts in file
    account* acc = malloc(sizeof(account));
    int numOfAcc = 0;
    while(fread(acc,sizeof(account),1,database)){
       numOfAcc++;
    }

    free(acc);
    fclose(database); 

    printf("The number of accounts in the data is %d", numOfAcc);
}

void printAccounts(char* filename){
    //Open file for reading
    FILE* database;
    database = fopen(file,"rb+");
    if(database == NULL){
        perror("[-]");
        exit(EXIT_FAILURE);
    }
    
    printf("The customers are:\n");
    
    //Prints out all accounts in file
    account* acc = malloc(sizeof(account));
    while(fread(acc,sizeof(account),1,database)){
        printf("%u\t%-20s\t%-10.2lf\t%.2lf\n",acc->accountNumber, acc->customerName, acc->creditAvaliable, acc->balanceDue);
    }

    free(acc);
    fclose(database); 
}

void flushstdin(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void clearFile(char* filename){
    FILE* myfile = fopen(filename,"w");
    fclose(myfile);
}

void displayMenu(){
    printf("\tA: Append new customer\n");
    printf("\tL: Show a list of all accounts\n");
    printf("\tS: Show the number of customers in the database\n");
    printf("\tF: Given an account # find the position of the customer with that number\n");
    printf("\tR: Given the position number display the data of the account stored there\n");
    printf("\tQ: Exit program\n");

}

void getSelection(int selection){
    switch(selection){
        case 'A':
            append();
            break;
        case 'L':
            printAccounts(file);
            break;
        case 'S':
            printNumberofAccounts();
            break;
        case 'F':
            findPosition();
            break;
        case 'R':
            findAccount();
            break;
        case 'Q':
            break;
        default:
            printf("Invalid selection. Try again.\n");
            break;
    }

}