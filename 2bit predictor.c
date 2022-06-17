#include <stdio.h>
#define stronglyTaken 100
#define weaklyTaken 101
#define weaklyNotTaken 110
#define stronglyNotTaken 111
#define taken 1
#define notTaken 0

int event, answer;
int state = stronglyTaken;
int main ()
{
int event, answer;
for (;;)
{
    printf("choose event: 0 for taken and 1 for not taken \n\n", event, taken, notTaken);
    scanf("%d", &event);
        switch (state)
        {
                case stronglyTaken:
                    if (event == taken)
                    {
                        state = stronglyTaken;
                    }
                    else
                    {
                        if (event == notTaken)
                        {
                            state = weaklyTaken;
                        }
                    }
                break;

                case weaklyTaken:
                    if (event == taken)
                    {
                        state= stronglyTaken;
                    }
                    else
                    {
                        if (event == notTaken)
                        {
                            state = weaklyNotTaken;
                        }
                    }

                break;

                case weaklyNotTaken:
                    if (event == taken)
                    {
                        state = weaklyTaken;
                    }
                    else
                    {
                        if (event == notTaken)
                        {
                            state = stronglyNotTaken;
                        }
                    }

                break;

                case stronglyNotTaken:
                    if (event == taken)
                    {
                        state= weaklyNotTaken;
                    }
                    else
                    {
                        if (event == notTaken)
                        {
                            state = stronglyNotTaken;
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
