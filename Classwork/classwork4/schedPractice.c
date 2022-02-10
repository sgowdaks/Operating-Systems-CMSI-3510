
// Mac version

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// This is the data structure we will use to pass arguments to the children
struct MyData {
   char threadLetter;
   int  secondsToRun;
};

#define TIME_SLICE 40

// This is the child thread function that will be started by "pthread_create()"
static void *child( void *passedData ) {

   struct MyData *childData = (struct MyData*)passedData;  // data struct passed in
   char threadLetter = childData->threadLetter;            // remember the struct is a pointer
   int  timeToLive   = childData->secondsToRun;            //   so we use the "->" to access fields

   // Loop until the time to live expires, then exit
   while( timeToLive >= 0 ) {
      timeToLive -= TIME_SLICE;
      if( timeToLive <= 0 ) {
         if( (timeToLive + TIME_SLICE) != 0 ) {
            printf( "%c:%d:done\n", threadLetter, timeToLive + TIME_SLICE );
         }
      } else {
         printf( "%c:%d:%d\n", threadLetter, TIME_SLICE, timeToLive );
      }
      sleep( 1 );
   }
   return NULL;
}

int main(int argc, char *argv[]) {
  int n = 4;
  pthread_t child_thread1;
  pthread_t child_thread2;
  pthread_t child_thread3;
  pthread_t child_thread4;

  struct MyData threads[4];

  pthread_t *pthread_add[] = {&child_thread1, &child_thread2, &child_thread3, &child_thread4};
  int k = 1;
  for(int i = 0; i < 4; i = i+1 ){

    threads[i].threadLetter = *argv[k];
    threads[i].secondsToRun = atoi((argv[k+1]));
    k = k + 2;
    pthread_create(pthread_add[i], NULL, child,(void *) &threads[i]);
  }
    return 0;
}
