#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

static void *child(void *ignored) {
    while(1) {
        sleep(5);
        printf("Waiting...\n");
    }
}

int main(int argc, char *argv[]) {
    pthread_t child_thread;
    char str;

    if(pthread_create(&child_thread, NULL, child, NULL) != 0){
      printf("Error In creating the thread");
    }
    printf("Press ENTER to cancel the thread.\n");
    while(1){
      str = fgetc(stdin);
      if(str == 0x0A){
        pthread_cancel(child_thread);
          printf("The thread has been cancelled.");
          break;
        }
      }
    
    return 0;
}
