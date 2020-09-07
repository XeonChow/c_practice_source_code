#include <stdio.h>
#define NUM 5
int max_index (const double *, int );

int main (void)
{
    double arr[NUM] = {1.2, 3.14, -4.4, 4.98, 4.99};
    printf ("The index of max number in the array is %d.\n", max_index(arr, NUM));
    return 0;
}

int max_index (const double * p, int n)
{
    int index = 0;
    double max = * p;
    for (int i = 0; i < NUM; i++)
    {
        if (max < *(p + i))
        {
            max = *(p + i);
            index = i;
        }
    }
    return index;
}