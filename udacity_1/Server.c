#include"Server.h"
#include <stdio.h>
#include <stdlib.h>
#include"DataBase.h"


static int global_index=0;


EN_transState_t recieveTransactionData(ST_transaction_t *transData)

{
 EN_transState_t Returned;
 Returned=isValidAccount(&(transData->cardHolderData));//pass card holder data address to isValidAccount function;
 if(Returned==DECLINED_STOLEN_CARD)
 {
    transData->transState=DECLINED_STOLEN_CARD;
    return(DECLINED_STOLEN_CARD);
    printf("DECLINED_STOLEN_CARD\n");
 }


 Returned=isAmountAvailable(&transData->terminalData);
    if(Returned==LOW_BALANCE)//care here
    {
        transData->transState=DECLINED_INSUFFECIENT_FUND;
        return(DECLINED_INSUFFECIENT_FUND);
        printf("DECLINED_INSUFFECIENT_FUND\n");
    }



 Returned=saveTransaction(transData);
 if(Returned==SAVING_FAILED)
 {
     transData->transState=INTERNAL_SERVER_ERROR;
     return(INTERNAL_SERVER_ERROR);
     printf("INTER_SERVER_ERROR\n");
 }

 else
    accounts[global_index].balance-=transData->terminalData.transAmount;
    printf("your balance is now ::%f\n",accounts[global_index].balance);
    printf("APPROVED\n");
    return(APPROVED);
}






EN_serverError_t isValidAccount(ST_cardData_t *cardData)
{
    int flag=0;
    //we will loop in database array (ACCOUNTS) i declared its size to 3
    //to detect the validity
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(cardData->primaryAccountNumber[j]==accounts[i].primaryAccountNumber[j])
            {
                flag++;
                if(flag==20)
                {
                    global_index=i;
                    return(OKAYZ);
                }
            }
            else
            {
                flag=0;
                break;
            }


       }
    }
    printf("Not Valid Account");
    return(DECLINED_STOLEN_CARD);
}





EN_serverError_t isAmountAvailable(ST_terminalData_t *termData)
{


            if(termData->transAmount<=accounts[global_index].balance)
            {
                return(OKAYZ);
            }
             else
                return(LOW_BALANCE);



}




EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
    printf("if u want to decline the transaction enter X ::\n");
    char input;
    scanf("%c",&input);
    scanf("%c",&input);
    if(input=='X')
    {
        printf("cancled\n");
        return(SAVING_FAILED);
    }
    else
    {
        transactions[TransIndex].cardHolderData=transData->cardHolderData;
        transactions[TransIndex].terminalData=transData->terminalData;
        transactions[TransIndex].transState=transData->transState;
        transactions[TransIndex].transactionSequenceNumber=TransIndex;
        TransIndex++;
        return(OKAYZ);
    }
}
