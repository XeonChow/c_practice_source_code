#include <stdio.h>

double power (double, int);
double getnum (void);
int getint (void);

int main (void)
{
    double base;
    int n;
    printf ("Please enter the base: ");
    base = getnum ();
    printf ("Please enter the power: ");
    n = getint ();
    printf ("%f to the power of %d is %e\n", base, n, power (base, n));
    return 0;
}

double power (double base, int n)
{
    double value;

    if (n == 0)
        value = 1;
    else if (n > 0)
        value = base * power (base, n - 1);
    else if (n < 0)
        {
            n = -n;
            value = base * power (base, n - 1);
            value = 1.0 / value;
        }
    return value;
}

double getnum (void)
{
    double num;
    
    while ( scanf ("%lf", &num) != 1)
    {
        scanf ("%*s");
        printf ("Please enter a number!\n");
    }
    return num;
}

int getint (void)
{
    int num;
    
    while ( scanf ("%d", &num) != 1)
    {
        scanf ("%*s");
        printf ("Please enter an integer!\n");
    }
    return num;
}