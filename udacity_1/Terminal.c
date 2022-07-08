
#include"Terminal.h"
#include <stdio.h>
#include <stdlib.h>


EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    printf("enter the Transaction Date in format of DD/MM/YYYY !! ");
    uint8_t input[10]="";
    int count_Size=0;
    gets(input);
     /// size of Transaction Date input
       for(int i=0;i<10;i++)
    {
        if(input[i]!=0)
            count_Size++;
    }
    //check on the size of input
    if(count_Size!=10)
        return(WRONG_DATE);

    /*limitations on Date
    1)days not equal or less 00
    2)months not more that 12 and not equal or less 00
    3)years not less than 2022
    */
    int limitDays=0;
    int limitMonths=0;
    int limitYears=0;
    limitDays =(input[0]-48)*10+(input[1]-48);
    limitMonths =(input[3]-48)*10+(input[4]-48);
    limitYears =(input[6]-48)*1000+(input[7]-48)*100+(input[8]-48)*10+(input[9]-48);
    ///
    if(limitDays<=0)
    {
        return(WRONG_DATE);

    }
        if(limitMonths>12||limitMonths<00)
    {
        return(WRONG_DATE);

    }
        if(limitYears<2022)
    {
        return(WRONG_DATE);

    }



    for(int i=0;i<10;i++)
    {
        termData->transactionDate[i]=input[i];
    }
    return(OKAY);

}


EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
    //transaction date format DD/MM/YYYY
    //EXPIREY DATE FORMANT MM/YY
    int ExpireMonth=cardData->cardExpirationDate[0]-48;
    ExpireMonth*=10;
    ExpireMonth+=cardData->cardExpirationDate[1]-48;


    int ExpireYear=cardData->cardExpirationDate[3]-48;
    ExpireYear*=10;
    ExpireYear+=cardData->cardExpirationDate[4]-48;




    int TransctMonth=termData->transactionDate[3]-48;
    TransctMonth*=10;
    TransctMonth+=termData->transactionDate[4]-48;


    int TransctYear=termData->transactionDate[8]-48;
    TransctYear*=10;
    TransctYear+=termData->transactionDate[9]-48;



    //check the expiration dates
    if(ExpireYear<TransctYear)
    {
        return(EXPIRED_CARD);
    }
    if((ExpireYear==TransctYear)&&(ExpireMonth<TransctMonth))
    {
        return(EXPIRED_CARD);
    }
    return(OK);
}



EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    float input=0;
    printf("enter your amount to transact ");
    scanf("%f",&input);
    if(input<=0)
    {
        return(INVALID_AMOUNT);
    }
    termData->transAmount=input;
    return(OKAY);
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    if(termData->transAmount>termData->maxTransAmount)
        return(EXCEED_MAX_AMOUNT);
    else
        return(OKAY);
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
    float input=0;
    printf("ENTER THE MAX AMOUNT OF TERMINAL!! ");
    scanf("%f",&input);
    if(input<=0)
    {
        return(INVALID_MAX_AMOUNT);
    }
    else
    {
        termData->maxTransAmount=input;
        return(OKAY);
    }

}
