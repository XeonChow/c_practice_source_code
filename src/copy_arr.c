#include <stdio.h>
void copy_arr (double source[], double target[], int n);
void copy_ptr (double *, double *, int n);
void print_arr (double *, int n);

int main (void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    copy_arr (source, target1, 5);
    copy_ptr (source, target2, 5);
    print_arr (target1, 5);
    print_arr (target2, 5);
    return 0;
}

void copy_arr (double source[], double target[], int n)
{
    for (int i=0; i < n; i++)
        target[i] = source[i];
}

void copy_ptr (double * source, double * target, int n)
{
    for (int i = 0; i < n; i++)
        *(target + i) = *(source + i);
}

void print_arr (double *p, int n)
{
    for (int i= 0; i < n; i++)
        printf ("%3.1f ", *(p + i));
    printf ("\n");
}