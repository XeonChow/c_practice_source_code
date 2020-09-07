#include <stdio.h>
void to_binary (int n);

int main (void)
{
    unsigned long number;

    printf ("Enter an integer, q to quit: \n");
    while (scanf ("%ul", &number) == 1)
    {
        printf ("Binary equivalent: ");
        to_binary (number);
        putchar ('\n');
        printf ("Enter an integer, q to quit: \n");
		printf ("test");
    }
}

void to_binary (int n)
{
    int r;

    r = n % 2;
    if (n >= 2)
        to_binary (n / 2);
    putchar ('0' + r);

    return;
}
