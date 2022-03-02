#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>

struct ThreadData_t {
  int threadID;
  int time;
  int startAddress;
  int *physical;
} ThreadData_t;



static void *child( void *passedData ) {

  struct ThreadData_t *childData = (struct ThreadData_t*)passedData;
   int p = childData->startAddress;
   int times  = childData->time;
   int *phy = childData->physical;
   for(int i = p; i< p + 4096;i++){
     // *(phy + i) = *(p + i);
     printf("%d\n", i);
   }
   return NULL;
}

int main(){


  int* virtual = malloc(sizeof(int)*4096*6);
  for(int i = 0; i < (4096*6); i++){
      virtual[i] = rand() % 65535;
  }

  int* physical = malloc(sizeof(int)*4096*4);

  int pointers[6];
  int n = 1;
  for(int i = 0;i<6;i++){
    pointers[i] = *(virtual + (4096 * n));
    n = n + 1;
  }

  pthread_t child_thread1;
  pthread_t child_thread2;
  pthread_t child_thread3;
  pthread_t child_thread4;
  pthread_t child_thread5;
  pthread_t child_thread6;
  struct ThreadData_t threads[6];
  pthread_t *pthread_add[] = {&child_thread1, &child_thread2, &child_thread3, &child_thread4, &child_thread5, &child_thread6};
  for(int i = 0; i < 6; i = i+1 ){

    threads[i].threadID = i + 1;
    threads[i].time =30;
    threads[i].startAddress = pointers[i];
    threads[i].physical = physical;
    pthread_create(pthread_add[i], NULL, child,(void *) &threads[i]);
  }

}
