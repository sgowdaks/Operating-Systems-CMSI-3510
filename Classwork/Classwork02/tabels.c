#include<stdio.h>
int main(){
  int a = -10;
  // char str2[2] = ["ODD","EVEN"]
  for(int i = a;i<11;i++){
    int k = i*i;
    printf("%d %d ",i,i*i);
    if(i%2 == 0){
      printf("EVEN\n");
    }else{
      printf("ODD\n");
    }
  }
}
