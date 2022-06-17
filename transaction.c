#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int balance =40;
pthread_mutex_t mutexBalance= PTHREAD_MUTEX_INITIALIZER;

void* deposit(int sum)
{
    pthread_mutex_lock(&mutexBalance);
    {
    int currbalance = balance;
    currbalance += sum;
    balance = currbalance;
    //printf(" balance  %d\n", balance);
    }
    pthread_mutex_unlock(&mutexBalance);

}
void* withdraw (int sum)
{
    pthread_mutex_lock(&mutexBalance);
    {
    int currbalance = balance;
    if(currbalance > 0)
    {
        currbalance -= sum;
    }
    balance = currbalance;
     //printf(" balance  %d\n", balance);
    }
    pthread_mutex_unlock(&mutexBalance);

}
int main()
{
 for(;;)

 {


  pthread_t th1, th2, th3;

  pthread_create(&th1, NULL, deposit, (int) 100 );//printf(" balance1  %d\n", balance);
  pthread_create(&th2, NULL, withdraw, (int) 200 );//printf(" balance2  %d\n", balance);
  pthread_create(&th3, NULL, deposit, (int) 4500 );//printf(" balance3  %d\n", balance);



  pthread_join(th1, NULL);
  pthread_join(th2, NULL);
  pthread_join(th3, NULL);


  usleep(2000000);
 printf(" balance  %d\n", balance);
printf("\n\n -------------------------- \n\n");

  // balance=0;
 }
 return 0;
}
