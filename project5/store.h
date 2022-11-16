//Project 5
//Name:Jackie Li Email:jli306@csu.fullerton.edu

#ifndef STORE_H
#define STORE_H

typedef struct{
    int quantity;
    char itemName[100];
    double total;
}item;


void flushstdin(void);

void displayMenu();

void displayMerch();

void viewCart(item*cart, int size);

void getSelection(int selection, item* cart, int* sizeOfCart,double* total);

#endif