#include <stdio.h>

void chline (char, int, int);

int main (void)
{
    int i = 3, j = 10;
    char c = 'x';

    chline (c, i, j);
    return 0;
}

void chline (char c, int i, int j)
{
    int x, y;

    for (x = 1; x < i; x++)
        printf ("*");
    for (y = i; y <=j; y++)
        printf ("%c", c);
    printf ("\n");
}