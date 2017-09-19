#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  int i = atoi(argv[1]); 
  if(i==0){
     printf("%d", 0);
   }
   else{
    for(int x = 1; x<= i; x++ ){
      printf("%d\n",7*x);
   }
 }
 return EXIT_SUCCESS;
}