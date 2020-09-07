#include <stdio.h>
void to_base_n (int, int);
int getint (void);


int main (void)
{
    unsigned long number;
    int base;

    printf ("Enter a base integer: ");
    base = getint ();
    printf ("Enter an integer, q to quit: \n");
    while (scanf ("%ul", &number) == 1)
    {
        printf ("%d base equivalent: ", base);
        to_base_n (base, number);
        putchar ('\n');
        printf ("Enter an integer, q to quit: \n");
    }
}

void to_base_n (int base, int num)
{
    int r;

    r = num % base;
    if (num >= base)
        to_base_n (base, num / base);
    putchar ('0' + r);

    return;
}

int getint (void)
{
    int num, status;
    
    while ( (status = scanf ("%d", &num)) != 1 || (num < 2 || num >10))
    {
        if (status != 1)
            scanf ("%*s");
        printf ("Please enter an integer between 2 and 10!\n");
    }
    return num;
}