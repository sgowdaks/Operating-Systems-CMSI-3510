#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]  ) {
  int* ptr;
  int n = atoi(argv[1]);
  ptr = (int*)malloc(n * sizeof(int));
  for(int i = 0; i < n; i++){
      ptr[i] = rand() % 100;
}
printf("Array is filled!");
int k = 4065;
while(k < n){
  printf("array element at %d %d \n",k,ptr[k]);
  k = k + 4095;
}
free(ptr);
return 0;
}
