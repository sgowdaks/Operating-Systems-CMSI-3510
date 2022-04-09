#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(){
  pid_t returnedValue = fork();
  int filedes;
  if(returnedValue < 0){
      perror("error forking");
      return -1;
  } else if (returnedValue == 0){

        //   if(close(STDOUT_FILENO) < 0){
        //       perror("error closing standard output");
        //       return -1;
        //   }

        filedes = open("/etc/passwd", O_RDONLY);
        if(filedes < 0){
          perror("error opening /etc/passwd");
        }
        dup2(filedes, 0);
        execlp("tr", "tr", "a-z", "A-Z",  NULL); // ps with option letter l
        perror("error executing tr");
        return -1;
  } else {
        if(waitpid(returnedValue, 0, 0) < 0){
        perror("error waiting for child");
        return -1;
      }
  }
}
