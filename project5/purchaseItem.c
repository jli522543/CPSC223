//Project 5
//Name:Jackie Li Email:jli306@csu.fullerton.edu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"

//Get total with given quantity of item asked for
double getTotal(int quantity, char * item){
    double total;
    char * cost = strstr(item,"$") + 1;
    sscanf(cost, "%lf", &total);
    total = total * quantity;
    return total;
}

//Search for user requested item in inventory file
char* searchItem(char * userRequest){
    
    char currItem[200];
    //Search file for user request
    FILE* inventory;
    inventory = fopen("inventory.txt", "r");
    
    //Read each line from file to match with first 8 letters of user request    
    while(fgets(currItem,200,inventory)!=NULL){
        if(strncmp(userRequest,currItem,8) == 0){
            char* match = malloc(200);
            strtok(currItem,"\n");
            strcpy(match,currItem);
            fclose(inventory);
            return match;
        }
    }
    fclose(inventory);
    
    //Returns null if user requested item was not found in inventory
    return NULL;
}

void purchaseItem(item* cart,int* size, double* totalCost){
    
    //Prompt user for item name
    char userReq[200];
    printf("Enter name of item wanted.  Must match on first 8 characters: ");
    fgets(userReq,200,stdin);

    //Search file for user request
    char * match = searchItem(userReq);
    
    int quantity;
    double total;

    //If item was found in inventory add item to shopping cart
    if(match!=NULL){
        strcpy(cart[*size].itemName, match);
        printf("Please enter quantity: ");
        scanf("%d",&quantity);
        flushstdin();
        cart[*size].quantity = quantity;
        total = getTotal(quantity,match);
        cart[*size].total = total;
        (*size)++;
        (*totalCost)+=total;
        printf("Item was added to shopping cart.\n");   
    }
    //Item was not found
    else{
        printf("The item you are looking for is not in stock\n");
    }
    
}

void checkout(item* cart, int size,double totalCost){
    
    //Open reciept for writing
    FILE * reciept;
    reciept = fopen("gse.txt", "w");

    //Reciept header
    fprintf(reciept,"%s", "Golden State Emporium\n");
    fprintf(reciept,"%s", "We do our best to serve our customers\n\n");
    fprintf(reciept,"%s", "Today's purchases:\n\n");
    fprintf(reciept,"\t%s\t\t\t\t\t%s\t%s\n", "Item","Quantity","Cost");

    //Writes items in cart to reciept
    for(int i = 0; i < size; i++){
        fprintf(reciept, "\t%s\t\t%d\t\t$%.2f\n", cart[i].itemName ,cart[i].quantity,cart[i].total);
    }
    
    //Prints out total and good bye message
    fprintf(reciept,"\n%s$%.2f\n", "Amount paid: ",totalCost);
    fprintf(reciept,"%s", "Thank you for shopping at GSE.\n");
    fclose(reciept);

    //Good bye message in console
    printf("\nYour reciept is being generated\n");
    printf("Please view your reciept in the file gse.txt\n");
    printf("Thank you for shopping at our store. Bye\n");
}