#include <stdio.h>
#include <stdlib.h>
//f(N) = 3*(N-1)+[2*f(N-1)]-1
int recursion(int x) {
  if(x<=0)
    {
      return 2;
    }
  else{
    return 3 * (x-1) + recursion(x-1)+1;
}
}
int main(int argc, char **argv) {
   int i = atoi(argv[1]); 
   if(i==0){
     printf("%d\n",recursion(0));
   }
   else{
   printf("%d\n",recursion(i));
}
return EXIT_SUCCESS;
}
