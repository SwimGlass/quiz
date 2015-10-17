/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

int max_so_far      = INT_MIN;

int max(int a ,int b)
{
    return (a>b?a:b);
}

int maxSubArray(int array[],int max_so_far,int max_ending_here,int max_element,int size){
        max_ending_here = max(max_ending_here + array[0], 0);
        max_so_far      = max(max_ending_here, max_so_far);
        max_element     = max(max_element, array[0]);
        size--;
    return maxSubArray(&array[(sizeof(array)/sizeof(int)-size)],max_so_far,max_ending_here,max_element,size);
}

int main()
{
    int array[] = {-1,4,-2,5,-5,2,-20,6};
    int max_ending_here = 0;
    int max_element     = INT_MIN;
    maxSubArray(array,max_so_far,max_ending_here,max_element,(sizeof(array)/sizeof(int)));
    if (max_so_far == 0)
        max_so_far = max_element;

    printf("%d\n", max_so_far);
    return 0;
}
