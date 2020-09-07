#include <stdio.h>
int main (void)
{
    int grid[30][100] = {0};
    printf ("&grid[22][56] = %p\n", &grid[22][56]);
    printf ("&grid[22][0] = %p,     grid[22] = %p\n",
                &grid[22][0],       grid[22]);
    printf ("&grid[0][0] = %p,      grid[0] = %p,   grid = %p\n",
                &grid[0][0],        grid[0],        grid);
    return 0;
}