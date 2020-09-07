#include <stdio.h>
#define ROWS 3 
#define COLS 5
void input_arr (double (*)[COLS], int);
double avg_arr (const double *, int);
double avg_arr_2d (const double (*)[COLS], int);
double get_num (void);
double max (const double (*)[COLS], int);

int main (void)
{
    double arr_2d[ROWS][COLS];
    printf ("Please type in 3 arrays, every one of which");
    printf (" has 5 double numbers.\n");
    input_arr (arr_2d, ROWS);
    printf ("Average of the first array is: %5.3f\n", avg_arr (arr_2d[0], COLS));
    printf ("Average of the second array is: %5.3f\n", avg_arr (arr_2d[1], COLS));
    printf ("Average of the third arry is: %5.3f\n", avg_arr (arr_2d[2], COLS));
    printf ("Average of all numbers is: %5.3f\n", avg_arr_2d (arr_2d, ROWS));
    printf ("The max of all numbers is: %5.3f\n", max (arr_2d, ROWS));
    return 0;
}

double get_num (void)
{
    double num;
    char ch;

    while (scanf("%lf",&num) != 1) //judge if the input is a number.
    {
        while ((ch = getchar()) != '\n') //skip the unqualified characters.
            putchar (ch);               //and show those unqualified charaters.
        printf (" is not a double number, please enter a double.\n");
    }
    return num;
}

void input_arr (double (*arr)[COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        printf ("Please enter array No. %d:\n", i);
        for (int j = 0; j < COLS; j++)
            *(*(arr + i) + j) = get_num();
    }
}

double avg_arr (const double *arr, int n)
{
    double sum = 0;
    double avg;
    for (int i = 0; i < n; i++)
        sum += *(arr + i);
    avg = sum / n;
    return avg;
}

double avg_arr_2d (const double (*arr)[COLS], int rows)
{
    double sum = 0;
    double avg;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < COLS; j++)
            sum += *(*(arr + i) + j);
    avg = sum / (rows * COLS);
    return avg;
}

double max (const double (*arr)[COLS], int rows)
{
    double max = **arr;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < COLS; j++)
        {
            if (max < *(*(arr + i) + j))
                max = *(*(arr + i) + j);
        }
    return max;
}