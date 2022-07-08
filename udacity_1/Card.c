
#include"Card.h"
#include <stdio.h>
#include <stdlib.h>

EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    printf("Enter Your Card Name!! ");
    char input [25]="";
    gets(input);
    int coun_Size=0;

    /// size of name
    for(int i=0;i<25;i++)
    {
        if(input[i]!=0)
            coun_Size++;
    }


    ////check the name size to return (OK,WRONG NAME)
    if(coun_Size<20||coun_Size>24||coun_Size==0)
    {
        return(WRONG_NAME);
    }

    else
          //loop to input in struct
    {
        for(int i=0;i<25;i++)
            {
            cardData->cardHolderName[i]=input[i];
            }
        return(OK);
    }
}

//////////////////////*/////////////////*//////////////////*/////////

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    printf("enter Your Card Expirey Date in format of [MM/YY] !! ");
    int coun_Size=0;//size of input
    char input [5]="";
    gets(input);
    //size of Date input
    for(int i=0;i<5;i++)
    {
        if(input[i] != 0)
            coun_Size++;
    }
    /*limitations on Date input
    1)not more than 5 chacaters
    2)not more that 12 in months >>not less that 22 in years>>and not ==00/00
    */
    if(coun_Size<5||coun_Size>5)
    {
        return(WRONG_EXP_DATE);

    }
    //limit variables
  int static limitYear=0;
  int static limitMonths=0;
  limitMonths=(input[0]-48)*10+(input[1]-48);
  limitYear  =(input[3]-48)*10+(input[4]-48);

//use them to limit the invalid expirey date

  if(limitMonths>12||limitMonths<=0)
    return(WRONG_EXP_DATE);
  if(limitYear<=0)
    return(WRONG_EXP_DATE);
    //input Date in Struct

    for(int i=0;i<5;i++)
    {
        cardData->cardExpirationDate[i]=input[i];
    }
    return(OK);

}

//////////////////////*/////////////////*//////////////////*/////////

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
  printf("Enter your PAN code in 20 places not less than 16 char and not more than 19 char\n");
  char input[20]="";
  int coun_Size=0;
  gets(input);
  //size of Date input
    for(int i=0;i<20;i++)
    {
        if(input[i] != 0)
            coun_Size++;
    }
   /*limitations on PAN code
   1)not more than 19char alphanumeric
   2)not less than 16 char
    */
    if(coun_Size>19||coun_Size<16)
        return(WRONG_PAN);

   //input data to struct
   for(int i=0;i<20;i++)
    {
        cardData->primaryAccountNumber[i]=input[i];
    }
    return(OK);
}

