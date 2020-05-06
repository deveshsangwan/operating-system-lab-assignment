# include<stdio.h>
# include<pthread.h>
# include<stdlib.h>
# include<unistd.h>
# include<ctype.h>
# include<sys/types.h>
# include<sys/wait.h>
# include<semaphore.h>
#include<bits/stdc++.h>
# include<sys/sem.h>
using namespace std;

sem_t chopstick[100];
int n;
void * thread_func(void * pno) {
   int * ab = (int * ) pno;
   int no = * ab;
   int i, iteration = 5;
   for (i = 0; i < iteration; ++i) {
      sem_wait( & chopstick[no]);
      sem_wait( & chopstick[(no + 1) % n]);
      printf("\nPhilosopher %d –> Begin eating", no);
      sleep(1);
      printf("\nPhilosopher %d –> Finish eating\n", no);
      sem_post( & chopstick[no]);
      sem_post( & chopstick[(no + 1) % n]);
   }
   pthread_exit(NULL);
}

int main() {
   int i, res;
   pthread_t a_thread[100];
   printf("\nEnter the number of philosopher :");
   cin>>n;
   for (i = 0; i < n; ++i) {
      res = sem_init( &chopstick[i], 0, 0);
      if (res == -1) {
         perror("semaphore initialization failed");
         exit(1);
      }
  }
  for (i = 0; i < n; ++i) {
     int *ptr = new int;
     *ptr = i;
     pthread_create( &a_thread[i], NULL, thread_func, ptr);
     sem_post( &chopstick[i]);
  }
  for (i = 0; i < n; ++i) {
     pthread_join(a_thread[i], NULL);
  }
  printf("\n \n thread join succesfull\n");
  for (i = 0; i < n; ++i) {
     res = sem_destroy( &chopstick[i]);
  }
  exit(0);
}
