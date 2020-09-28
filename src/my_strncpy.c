#include <stdio.h>
#include <string.h>
#define MAX 101
char *my_strcpy (char *, const char *, unsigned int);
void get_string (char *);

int main (void)
{
    char obj[MAX];
    char src[MAX];
    char * ptr;

    puts ("Please enter a string.");
    get_string (src);
    my_strcpy (obj, src, 10);
    printf ("This is the copied string %s.\n",obj);

    return 0;
}

char *my_strcpy (char *s1, const char *s2, unsigned int n)
{
    for (int i = 0; i <= n && *(s2 + i) != '\0'; i++)
    {
        *(s1 + i) = *(s2 + i);
    }
    return s1;
}

void get_string (char * string)
{
    char *find;
    char *ptr;

    ptr = fgets (string, MAX, stdin);
    find = strchr (string, '\n');
    if (find)
        *find = '\0';
}
