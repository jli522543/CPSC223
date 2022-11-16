//Project 5
//Name:Jackie Li Email:jli306@csu.fullerton.edu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"
#include "purchaseItem.h"

//Clear garbage is stdin buffer
void flushstdin(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

//Display options from menu
void displayMenu(){
    printf("Here is our menu\n");
    printf("\tD=Display list of merchandise in current inventory\n");
    printf("\tP=Purchase an item\n");
    printf("\tR=Repeat this menu\n");
    printf("\tV=View shopping cart\n");
    printf("\tX=Exit,compute amount due, generate reciept\n");
}

//Display merchandise in inventory text file
void displayMerch(){
    char item[200];
    FILE* inventory;
    inventory = fopen("inventory.txt", "r");
    printf("\n");
    while(fgets(item,200,inventory)!=NULL){
        printf("%s",item);
    }
    fclose(inventory);
}

//View items in shopping cart
void viewCart(item*cart, int size){
    for(int i = 0; i < size; i++){
        printf("%d x %s Total:%.2f \n", cart[i].quantity ,cart[i].itemName,cart[i].total);
    }
}

//Perform operation that was selected by user
void getSelection(int selection, item* cart, int* size, double* total){
    switch(selection){
        case 'D':
            displayMerch();
            break;
        case 'P':
            purchaseItem(cart,size,total);
            break;
        case 'R':
            displayMenu();
            break;
        case 'V':
            viewCart(cart,*size);
            break;
        case 'X':
            checkout(cart,*size,*total);
            break;
        default:
            printf("Invalid selection.\n");
            break;
    }

}
