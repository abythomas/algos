#include <stdio.h>

int main(){
  int i=1;
  int prev=0;
  while(1==1)
  {
    i++;
    if(prev>i)
    {
      printf("%d\n",prev);
      return 0;
    }
    prev=i;
  }
}
