/*Issues
Two accounts can share the same account number
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "account.h"
#include "lender.h"

int main(){
    //Welcome Statements
    printf("Welcome to Sunflower Lenders, Inc.\n");
    printf("We provide the money you need\n");
    printf("Here is our menu\n");
    
    //Clear File for writing
    //clearFile(file);

    //Displays menu     
    displayMenu();

    //Initiate lender program  
    lender();


}