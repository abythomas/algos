#include <stdio.h>
#include <stdarg.h>

int sum(int count, ... )
{
      va_list nums;
      va_start(nums, count);
      int sum = 0;
      for(int i = 0; i < count; ++i )
            sum += va_arg(nums, int);
      va_end(nums);
      return sum;
}

int main()
{
      int s=sum(6,1,2,12,5,13,75);
      printf("\n%d\n",s);
}
