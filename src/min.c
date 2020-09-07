#include <stdio.h>

double min (double, double);
double getnum (void);


int main (void)
{
    double a, b;
    printf ("Please enter the first number: ");
    a = getnum ();
    printf ("Please enter the second number: ");
    b = getnum ();
    printf ("The little one of %f and %f is %f.\n", a, b, min(a, b));
    return 0; 
}

double min (double a, double b)
{
    double min;
    
    min = (a < b)?a:b;
    return min; 
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