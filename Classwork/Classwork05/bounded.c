#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

   int mutex = 1;
   int full  = 0;
   int empty = 7;          // maximum of seven messages in buffer
   int x     = 0;

   int myWait( int s ) {
      return( --s );
   }

   int mySignal( int s ) {
      return( ++s );
   }

   static void *child(void *ignored) {
    while(1) {
        sleep(5);
        printf("Waiting...\n");
    }
}

   int main()
   {
      int n;
      void producer();
      void consumer();
      pthread_t child_thread1;
      pthread_t child_thread2;
      while(1){
      pthread_create(&child_thread1, NULL, producer, NULL);
      pthread_create(&child_thread2, NULL, consumer, NULL);
    }



      // while( 1 ) {

         // printf( "\n\n   1.Producer\n   2.Consumer\n   3.Exit" );
         // printf("\n      Enter your choice: ");
         // scanf("%d",&n);
         // switch( n ) {
         //    case 1:  if( (mutex == 1) && (empty != 0) ) {
         //                producer();
         //             } else {
         //                printf( "\nBuffer is full!!" );
         //             }
         //             break;
         //    case 2:  if( (mutex == 1) && (full != 0) ) {
         //                consumer();
         //             } else {
         //                printf("\nBuffer is empty!!");
         //             }
         //             break;
         //    case 3:
         //    default: exit( 0 );
         //             break;
         // }

         return 0;
      }



   void producer(void *ignored) {
     printf("consuler\n");
     if( (mutex == 1) && (empty != 0) ){
      mutex = myWait( mutex );
      full  = mySignal( full );
      empty = myWait( empty );
      x++;
      // printf( "\n  Producer produces the item %d", x );
      mutex = mySignal( mutex );

      printf( "\n  Producer produces the item %d", x );
    }else{
      printf("\nBuffer if full");
      sleep(5);
    }
   }

    void consumer(void *ignored)
   {
     if( (mutex == 1) && (full != 0) ) {
      mutex = myWait( mutex );
      full  = myWait( full );
      empty = mySignal( empty );
      printf( "\n  Consumer consumes item %d", x );
      x--;
      mutex = mySignal( mutex );
    }else{
      printf("\nBuffer is empty!!");
      sleep(5);
    }
   }

