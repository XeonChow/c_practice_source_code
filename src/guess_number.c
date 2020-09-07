#include <stdio.h>

int getchoice (void);
int getfirst (void);
void print_hint (int);
int main (void)
{
	const int LOW_BOUND = 0;
	const int UP_BOUND = 100;  
	int min, max, target;
	int choice;
	min = LOW_BOUND;
	max = UP_BOUND;
	target = (min + max)/2 + (min + max)%2;
	
	printf ("Think of a number between %d and %d and bear it in mind.\n", LOW_BOUND, UP_BOUND);
	print_hint (target);
	while ((choice = getchoice()) != 'q')
	{
		switch (choice)
		{
			case 'y': {
						printf("I know it is %d!\n", target);
						return 0;
			  			}
				  break;
			case 'b': {
				  	if ((target - min) == 1)
					  {
						  printf("I know, the number is %d!\n", min);
						  return 0;
					  }
					else
					{
						max = target;
						target = (min + max)/2 + (min + max)%2;
						print_hint(target);
					}
				  }
				  break;
			case 's': {
						if ((max - target) == 1)
						{
							printf ("I know, the number is %d!\n", max);
							return 0;
						}
						else
						{
							min = target;
							target = (min + max)/2 + (min + max)%2;
							print_hint(target);
						}
						break;
			default: printf("Error!\n");
					break;
			}
		}

	}
	return 0;
} 

void print_hint (int target)
{
	printf ("Is the number %d? Enter y if my guess is right.\n", target);
	printf ("Enter b if it's bigger or s if it's smaller.\n");
	printf ("Enter q to quit.\n");

}

int getfirst(void)
{
	int ch;

	ch = getchar();
	while (getchar() != '\n')
		continue;
	return ch;
}

int getchoice(void)
{
	int ch;

	ch = getfirst();
	while (ch != 'y' && ch != 'b' && ch != 's' && ch != 'q')
	{
		printf("Please enter y, b, s or q.\n");
		ch = getfirst();
	}
	return ch;
}