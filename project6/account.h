#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct{
    unsigned int accountNumber;
    char customerName[50];
    double creditAvaliable;
    double balanceDue;
}account;

#endif