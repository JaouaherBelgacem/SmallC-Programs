#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int Commoncounter=0;
int answer, eastCounter=0, westCounter=0, northCounter=0, southCounter=0;
int nbrEnterFans, nbrLeaveFans;

pthread_mutex_t mutexCounter= PTHREAD_MUTEX_INITIALIZER;

void EnterFan()
{

    printf("please enter the number of entering fans\n");
    scanf("%d", &nbrEnterFans);

}

void LeaveFun()
{
    printf("please enter the number of leaving fans\n" );
    scanf("%d", &nbrLeaveFans);

}

void *EastTurnstile (void *arg)
{
    pthread_mutex_lock(&mutexCounter);
    {
         printf(" This is the East Turnstile\n");
        printf("please identify whether entering fans:  type 1 or leaving fans: type 0 \n");
        scanf("%d", &answer);

        if (answer == 1)
        {
            EnterFan();
            eastCounter += nbrEnterFans;

        }
        else
        {
            LeaveFun();
            if(eastCounter - nbrLeaveFans >0 )
            {
                eastCounter= eastCounter- nbrLeaveFans;
            }

        }
         printf("The current East Counter state is %d: \n\n", eastCounter);

        }
        pthread_mutex_unlock(&mutexCounter);
}
void *WestTurnstile (void *arg)
{
    pthread_mutex_lock(&mutexCounter);
    {
        printf(" This is the West Turnstile\n");
        printf("please identify whether entering fans:  type 1 or leaving fans: type 0 \n");
        scanf("%d", &answer);

        if (answer == 1)
        {
            EnterFan();
            westCounter += nbrEnterFans;

        }
        else
        {
            LeaveFun();
            if(westCounter - nbrLeaveFans >0 )
            {
                westCounter= westCounter- nbrLeaveFans;
            }

        }
         printf("The current West Counter state is %d: \n\n", westCounter);


        }
        pthread_mutex_unlock(&mutexCounter);

}
void *NorthTurnstile (void *arg)
{
    pthread_mutex_lock(&mutexCounter);
    {
      printf(" This is the North Turnstile\n");
        printf("please identify whether entering fans:  type 1 or leaving fans: type 0 \n");
        scanf("%d", &answer);

        if (answer == 1)
        {
            EnterFan();
            northCounter += nbrEnterFans;

        }
        else
        {
            LeaveFun();
            if(northCounter - nbrLeaveFans >0 )
            {
                northCounter= northCounter- nbrLeaveFans;
            }

        }
         printf("The current North Counter state is %d: \n\n", northCounter);


    }
    pthread_mutex_unlock(&mutexCounter);
}

void *SounthTurnstile (void *arg)
{
    pthread_mutex_lock(&mutexCounter);
    {
      printf(" This is the South Turnstile\n");
        printf("please identify whether entering fans:  type 1 or leaving fans: type 0 \n");
        scanf("%d", &answer);

        if (answer == 1)
        {
            EnterFan();
            southCounter += nbrEnterFans;

        }
        else
        {
            LeaveFun();
            if(southCounter - nbrLeaveFans >0 )
            {
                southCounter= southCounter- nbrLeaveFans;
            }

        }
         printf("The current South Counter state is %d: \n\n", southCounter);


    }
    pthread_mutex_unlock(&mutexCounter);

}
int main()
{
   for(;;)

    {
        pthread_t th1, th2, th3, th4;

      pthread_create(&th1, NULL, EastTurnstile, NULL );
      pthread_create(&th2, NULL, WestTurnstile, NULL );
      pthread_create(&th3, NULL, NorthTurnstile,  NULL );
      pthread_create(&th4, NULL, SounthTurnstile, NULL );



      pthread_join(th1, NULL);
      pthread_join(th2, NULL);
      pthread_join(th3, NULL);
      pthread_join(th4, NULL);

      if(Commoncounter < 3000)
      {
          int sum = eastCounter + westCounter+ northCounter + southCounter;
          if(3000 - sum >=0)
          {
              Commoncounter+= sum;
          }
          else
          {
              do
              {
                  Commoncounter +=1;
              }while(Commoncounter < 3000);

              printf("the Stadium is FULL please wait !");
          }
      }
    printf("the number of visitors inside the stadium is: %d \n", Commoncounter);
    printf("--------------------------------------\n\n");
    }
      return 0;
}
