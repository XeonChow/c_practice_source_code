#include <stdio.h>
int main (void)
{
    printf ("%s, %p, %c", "We", "are", *("space farers" + 1));
    return 0;
}
