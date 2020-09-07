#include <stdio.h>
#define NUM 5
double diff (const double *, int);

int main (void)
{
    double arr[NUM] = {1.2, 3.14, -4.4, 4.98, 4.99};
    printf ("The difference between the max an min numbers in the array");
    printf ("is %4.2f.\n", diff (arr, NUM));
    return 0;
}

double diff (const double *p, int n)
{
    double max = *p;
    double min = *p;
    double diff;

    for (int i = 0; i < n; i++)
    {
        if (max < *(p + i))
            max = *(p + i);
        if (min > *(p + i))
            min = *(p + i);
        diff = max - min;
    }
    return diff;
}