#include <stdio.h>
#include <stdio.h>
#include "quicksort.h"  

void qs(int arr[],int l,int r)
{
    if(r > l)
    {
        int pivot = arr[r];
        int i = l - 1;
        int j = r;
        int temp;

        while(1)
        {
            while(arr[++i] < pivot);
            while(arr[--j] > pivot);

            if(i >= j) break;

            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
        
        temp = arr[i]; arr[i] = arr[r]; arr[r] = temp;

        qs(arr,i+1,r);
        qs(arr,l,i-1);
    }
}

