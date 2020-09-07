#include <stdio.h>
#define COLS 5
#define ROWS 3

void plus (int rows, int cols, const double arr1[rows][cols],
                               const double arr2[rows][cols],
                               double sum[rows][cols]);
void print (int rows, int cols, const double ar[rows][cols]);             

int main (void)
{
    int rows = 3;
    int cols = 5;
    double arr1[ROWS][COLS] = {
        {2.3, 3.4, 4.5, 5.6, 6.7},
        {7.8, 8.9, 9.1, 10.2, 11.3},
        {12.4, 13.5, 14.6, 15.7, 16.8}
    };
    double arr2[ROWS][COLS] = {
        {7.8, 8.9, 9.1, 10.2, 11.3},
        {12.4, 13.5, 14.6, 15.7, 16.8},
        {2.3, 3.4, 4.5, 5.6, 6.7}
    };
    double sum[rows][cols];
    plus (rows, cols, arr1, arr2, sum);
    printf ("Array1 is:\n");
    print (rows, cols, arr1);
    printf ("Array2 is:\n");
    print (rows, cols, arr2);
    printf ("The sum of array1 and array2 is:\n");
    print (rows, cols, sum);
    return 0;
}

void plus (int rows, int cols, const double arr1[rows][cols],
                               const double arr2[rows][cols],
                               double sum[rows][cols])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum[i][j] = arr1[i][j] + arr2[i][j];
}                               

void print (int rows, int cols, const double ar[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf ("%5.1f ", ar[i][j]);
        printf ("\n");
    }
}
