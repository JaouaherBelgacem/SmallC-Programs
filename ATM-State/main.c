#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define AtmOff 0
#define AtmOn 1
#define IDLE 2
#define ServingCustomer 3
#define CustomerAuthentification 4
#define Transaction 5

bool readCard= false, ejectCard= false , isOn= false;

char trigger[20], Answer[20];
int eventId;

int generalAtmState = AtmOff;

int mainFunctionsState= IDLE;

int subFunctionState = CustomerAuthentification;



int main()
{
    printf(" To turn on the ATM please type TurnOn \n to turn it off type TurnOff \n");
    getTrigger();
    printf("the event is \n %s\n\n", trigger);

     if (strcmp (trigger,"TurnOn") == 0)
    {
        generalAtmState= AtmOn;
        isOn = true;
        printf("check\n\n");
    }
    else
    {
        if (strcmp (trigger, "TurnOff") ==0)
        {
            generalAtmState= AtmOff;
            isOn = false;
        }
    }

    do{

        stateMachine();

      } while(isOn == true);
  }

void getTrigger()
{
    printf(" Please enter the trigger: \n ");
   scanf("%s", Answer);

   strcpy (trigger, Answer);

}
void stateMachine()
{
   switch(mainFunctionsState)
   {
    case IDLE:
        printf(" If you want to switch from IDLE to ServingCustomer \n please enter InsertedCard\n");
        getTrigger();

         if(strcmp (trigger, "InsertedCard")== 0)
         {
             readCard= true;
             printf("check\n");
         }
        if (readCard == true)
        {
            mainFunctionsState = ServingCustomer;
        }
    break;

    case ServingCustomer:
        {
            switch(subFunctionState)
            {
             case CustomerAuthentification:
                 printf("if you want to proceed your transaction please enter Approved\n");
                 getTrigger();
                if (strcmp (trigger, "Approved")==0)
                {
                    subFunctionState = Transaction;
                }
                break;

             case Transaction:
                printf("if you want to exit please enter finished or cancel\n");
                getTrigger();
                if (strcmp (trigger, "finished")==0 || strcmp (trigger, "cancel")==0)
                {
                    ejectCard= true;
                }
                if( ejectCard == true)
                {
                    mainFunctionsState = IDLE;
                    subFunctionState= CustomerAuthentification;
                }
              break;

             default:
             break;
            }
        }
        break;

        default:
        break;
   }
}
