#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define elevatorOff 0
#define elevatorOn 1
#define wait 2
#define ServingUser 3
#define controlLevel 4
#define desiredFloor 5

bool buttonpressedFloorSelected= false, openDoor= false , isOn= false;

char trigger[20], Answer[20];
int currentFloor, floorDesired;

int generalEleState = elevatorOff;

int mainFunctionsState= wait;

int subFunctionState = controlLevel;



int main()
{
    printf(" To turn on the elevator please type powerOn \n to turn it off type powerOff \n");
    getTrigger();
    printf("the event is \n %s\n\n", trigger);

     if (strcmp (trigger,"powerOn") == 0)
    {
        generalEleState= elevatorOn;
        isOn = true;
        printf("check\n\n");
    }
    else
    {
        if (strcmp (trigger, "powerOff") ==0)
        {
            generalEleState= elevatorOff;
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
    case wait:
        printf(" If you want to switch from wait to ServingUser \n please enter buttonPressed\n");
        getTrigger();

         if(strcmp (trigger, "buttonPressed")== 0)
         {
             printf("please enter the floor desired\n");
             scanf("%d", &floorDesired);

             buttonpressedFloorSelected= true;
             printf("check\n");
         }
        if (buttonpressedFloorSelected == true)
        {
            mainFunctionsState = ServingUser;
        }
    break;

    case ServingUser:
        {
            switch(subFunctionState)
            {
             case controlLevel:
                 printf(" please enter current Floor\n");
                 scanf("%d", &currentFloor);
                if (currentFloor == floorDesired)
                {
                    subFunctionState = desiredFloor;
                }
            break;

             case desiredFloor:
                printf("if you want to exit please exit\n");
                getTrigger();
                if (strcmp (trigger, "exit")==0)
                {
                    openDoor= true;
                }
                if( openDoor == true)
                {
                    mainFunctionsState = wait;
                    subFunctionState= controlLevel;
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
