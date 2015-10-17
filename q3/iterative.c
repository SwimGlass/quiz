/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

int max(int a, int b)
{
    return ((a>b)?a:b);
}

int main(void)
{
    int array[] = {-1,4,-2,5,-5,2,-20,6};
    int max_so_far = INT_MIN,max_ending_here = 0;
    int i;
    for(i=0;i < (sizeof(array)/sizeof(int));i++){
        max_ending_here = max(max_ending_here + array[i],0);
        max_so_far = max(max_ending_here,max_so_far);
    }
    if(max_so_far < 0) max_so_far = 0;
    printf("%d\n",max_so_far);
    return 0;
}
