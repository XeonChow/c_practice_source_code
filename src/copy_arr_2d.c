#include <stdio.h>
#define COLS 5
#define ROWS 5
void copy_ptr (const double *, double *, int);
void copy_arr_2d (const double (*) [COLS], double (*) [COLS], int);
void print_arr_2d (const double (*) [COLS], int);

int main (void)
{
    double matrix[ROWS][COLS] = {
        {1.2, 2.34, 3.5, 55.3, 5.4},
        {1.2, 2.34, 3.5, 55.3, 5.4},
        {1.2, 2.34, 3.5, 55.3, 5.4},
        {1.2, 2.34, 3.5, 55.3, 5.4},
        {1.2, 2.34, 3.5, 55.3, 5.4}
    };

    double target[ROWS][COLS];
    copy_arr_2d (matrix, target, ROWS);
    print_arr_2d (target, ROWS);
    return 0;
}

void copy_ptr (const double * source, double * target, int cols)
{
    for (int i = 0; i < cols; i++)
        *(target + i) = *(source + i);
}

void copy_arr_2d (const double (* source) [COLS], double (* target) [COLS], int rows)
{
    for (int i = 0; i < rows; i++)
        copy_ptr (*(source + i), *(target + i), COLS);
}

void print_arr_2d (const double (* p) [COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf ("%4.2f ", *(*(p + i) + j));
        printf ("\n");
    }
}