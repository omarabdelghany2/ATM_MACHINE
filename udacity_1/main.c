#include <stdio.h>
#include <stdlib.h>
#include"Card.h"
#include"Terminal.h"
int main()
{
/*
    EN_cardError_t cardReturn;

    ST_cardData_t cardData;



    cardReturn = getCardHolderName(&cardData);
    while(cardReturn == WRONG_NAME)
    {
        printf("Wrong name\n");
        cardReturn=getCardHolderName(&cardData);
    }
     printf("OK\n");




    cardReturn=getCardExpiryDate(&cardData);
    while(cardReturn == WRONG_EXP_DATE)
    {
        printf("Wrong Exp_DATE\n");
        cardReturn=getCardExpiryDate(&cardData);
    }
    printf("OK\n");



    cardReturn=getCardPAN(&cardData);
    while(cardReturn==WRONG_PAN)
    {
        printf("Wrong PAN\n");
        cardReturn=getCardPAN(&cardData);
    }
    printf("OK\n");



//////////////////////////////////lets go to terminal
    printf("HI IM TERMINAL ENTER UR CARD PLS !!\n");
    ST_terminalData_t terminalData;
    EN_terminalError_t terminalReturn;


//get the date of transction
terminalReturn = getTransactionDate(&terminalData);
  while(terminalReturn==WRONG_DATE)
     {
        printf("WRONG Date\n");
        terminalReturn = getTransactionDate(&terminalData);
     }
    printf("OK\n");


//check for expired cards
terminalReturn=isCardExpired(&cardData,&terminalData);

if(terminalReturn==EXPIRED_CARD)
{
    printf("expired card\n");
    return(0);
}

//set max amount to terminal of transcation
terminalReturn=setMaxAmount(&terminalData);
while(terminalReturn==INVALID_MAX_AMOUNT)
{
    printf("INVALID_MAX_AMOUNT\n");
    terminalReturn=setMaxAmount(&terminalData);
}


//Set the amount u want to transact
terminalReturn=getTransactionAmount(&terminalData);
while(terminalReturn==INVALID_AMOUNT)
{
    printf("INVALID_AMOUNT\n");
    terminalReturn=getTransactionAmount(&terminalData);
}
///Check if the amount to transact is below the max or not
terminalReturn=isBelowMaxAmount(&terminalData);
if(terminalReturn==EXCEED_MAX_AMOUNT)
{
    printf("u exceed the max amount\n");
    return(0);
}

*/
////////////////////////////////////////////////////////////////////////////
printf("   HI  IM  SERVER !!!!       \n");
    return 0;
}
