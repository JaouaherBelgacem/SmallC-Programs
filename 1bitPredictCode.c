#include <stdio.h>
#define predictTaken 100
#define predictNotTaken 101
#define taken 1
#define notTaken 0

int event, answer;
int state = predictTaken;
int main ()
{
int event, answer;
for (;;)
{
    printf("choose event: 0 for taken and 1 for not taken \n\n", event, taken, notTaken);
    scanf("%d", &event);
        switch (state)
        {
                case predictTaken:
                    if (event == taken)
                    {
                        state = predictTaken;
                    }
                    else
                    {
                        if (event == notTaken)
                        {
                            state = predictNotTaken;
                        }
                    }
                break;

                case predictNotTaken:
                    if (event == taken)
                    {
                        state= predictTaken;
                    }
                    else
                    {
                        if (event == notTaken)
                        {
                            state = predictNotTaken;
                        }
                    }

                break;


                default:
                break;
                }
            printf (" The new state is = %d \t", state);
            printf ("\n\n");
            }
return 0;
}
