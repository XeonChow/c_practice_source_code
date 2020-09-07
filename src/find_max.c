#include <stdio.h>
#define NUM 5
int max (const int *, int);

int main (void)
{
    int arr[NUM] = {1, -4, 3, 5, 5};
    printf ("The max number in the array is %d.\n", max (arr, NUM));
    return 0;
}

int max (const int *p, int n)
{
    int max = *p;
    for (int i = 0; i < n; i++)
    {
        if (max < *(p + i))
            max = *(p + i);
    }
    return max;
}