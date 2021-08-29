#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./Algorithm/Sort/BucketSort.h"
int main()
{
    int array[8]= {8,7,6,5,4,2,2,1};
   Counting_Sort(array,8);
   for(int i=0;i<8;i++)
   {
      printf("%d ",array[i]);
   }
   return 0;
}