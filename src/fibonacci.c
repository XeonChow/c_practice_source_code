#include <stdio.h>

int fibonacci (int);
int getint (void);

int main (void)
{
    int n;

    printf ("Enter the No. of fibonacci array: ");
    n = getint ();
    printf ("Fibonacci array to item %d is:\n");
    for (int i = 1; i <= n; i++)
    {
        printf ("%d, ", fibonacci (i));
        if (i % 10 == 0)
            printf ("\n");
    }
    return 0;
}

int fibonacci (int n)
{
    int value;
    int a = 1, b = 1;

    if (n == 1 || n == 2)
        value = 1;
    else
    {
        for (int i = 3; i <= n; i++)
        {
            value = a + b;
            a = b;
            b = value;
        }
    }
    return value;
}

int getint (void)
{
    int num, status;
    
    while ( (status = scanf ("%d", &num)) != 1 || (num < 1 || num > 30))
    {
        if (status != 1)
            scanf ("%*s");
        printf ("Please enter an integer between 1 and 30!\n");
    }
    return num;
}