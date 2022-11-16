//Project 5
//Name:Jackie Li Email:jli306@csu.fullerton.edu

/*Issues
Shopping cart can only hold a max of 10 items
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"
#include "purchaseItem.h"

int main(){
    //Number of items in cart
    int itemsInCart = 0;
    //Total cost for all items in cart
    double totalCost;
    item* cart = malloc(10 * sizeof *cart);

    //Welcome message
    printf("Welcome to Golden State Emporium\n");
    
    //Display Menu
    char selection = 'R';
    getSelection(selection,cart,&itemsInCart,&totalCost);

    //Enter shop
    while(selection!='X'){
        //Prompt user for selection
        printf("\nPlease enter selection: ");
        
        //Check if getchar failed
        if((selection = getchar())==EOF)
            break;
        flushstdin();
        
        //Get selection that user has chose
        getSelection(selection,cart,&itemsInCart,&totalCost);
        
    }

    return 0;
}