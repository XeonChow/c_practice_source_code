#include <stdio.h>
#define COLS 5
#define ROWS 3
void copy (int rows, int cols, const double source[rows][cols], 
                                    double target[rows][cols]);
void print (int rows, int cols, const double ar[rows][cols]);

int main (void)
{
    int rows = 3;
    int cols = 5;
    double source[ROWS][COLS] = {
        {2.3, 3.4, 4.5, 5.6, 6.7},
        {7.8, 8.9, 9.1, 10.2, 11.3},
        {12.4, 13.5, 14.6, 15.7, 16.8}
    };
    double target[rows][cols];

    copy (rows, cols, source, target);
    printf ("The source array is:\n");
    print (rows, cols, source);
    printf ("The target array is:\n");
    print (rows, cols, target);
    return 0;
}

void copy (int rows, int cols, const double source[rows][cols],
                                        double target[rows][cols])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            target[i][j] = source[i][j];
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