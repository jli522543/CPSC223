#ifndef LENDER_H
#define LENDER_H

//File to be used for writing in account data
#define file "database.txt"

void lender();

//Print account at given position in file
void findAccount();

//Prints number of accounts that have been written to file
void printNumberofAccounts();

//Prints all account info in file
void printAccounts(char* filename);

//Add new account to end of file
void append();

//Clears content of a file
void clearFile(char* filename);

//Clears stdin buffer 
//SHOULD NOT BE USED IF STDIN BUFFER IS EMPTY!
void flushstdin(void);

//Runs selection inputted by user
void getSelection(int selection);

//Display options present in menu
void displayMenu();

//Prints position of account in file with account number given by suer
void findPosition();
#endif