#include <stdio.h>
#include <string.h>
#define MAX 101

char * string_in (char *, const char *);
void get_input (char *);

int main (void)
{
    char s1[MAX];
    char s2[MAX];
    char * ptr;

    puts ("Please enter the string to be searched.");
    get_input (s1);
    puts ("Please enter the string to be found.");
    get_input (s2);
    printf ("This is s1:\n%s\n", s1);
    printf ("This is s2:\n%s\n", s2);
    if ((ptr = string_in (s1, s2)) != NULL)
        printf ("Find %s in %s from %s.\n",
                s2, s1, ptr);
    else
        printf ("Find no %s in %s.\n",
                s2, s1);

    return 0;
}

char *string_in (char *s1, const char *s2)
{
    int len1 = strlen (s1);
    int len2 = strlen (s2);

    for (int i = 0; i <= len1 -len2; i++)
    {
        if (strncmp (s1 + i, s2, len2) == 0)
           return s1 + i;
    }
    return NULL;
}

void get_input (char * string)
{
    char * find;
    fgets (string, MAX, stdin);
    find = strchr (string, '\n');
    if (find)
        *find = '\0';
}
