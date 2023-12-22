#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
  char* a = (char* ) malloc(10* sizeof(char));
  char* b = (char* ) malloc(10* sizeof(char));

  for(int i = 0;i < 6;i++){
    a[i] = "a";
    b[i] = "b";
  }
  b[6] = "\0";
  printf("%d", strlen(a));
  printf("%d", strlen(b));
}
