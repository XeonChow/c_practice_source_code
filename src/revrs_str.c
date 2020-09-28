#include <stdio.h>
#include <string.h>
#define MAX 101

void revrs_str (char *);
void get_str (char *);

int main (void)
{
    char string[MAX];
    puts ("Please enter the string to reverse.");
    get_str (string);
    revrs_str (string);
    puts (string);

    return 0;
}

void revrs_str (char * string)
{
    int len = strlen (string);
    char tmp;

    for (int i = 0; (i * 2) < (len - 1); i++)
    {
        tmp = *(string + len - 1 -i);
        *(string + len - 1 -i) = *(string + i);
        *(string + i) = tmp;
    }
}

void get_str (char * string)
{
    char * find;
    fgets (string, MAX, stdin);
    find = strchr (string, '\n');
    if (find)
        *find = '\0';
}
