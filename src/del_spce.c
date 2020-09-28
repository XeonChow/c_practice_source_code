#include <stdio.h>
#include <string.h>
#define MAX 10

void del_spce (char *);
void get_str (char *);

int main (void)
{
    char string[MAX];

    puts ("Please enter a string.");
    get_str (string);
    puts (string);
    del_spce (string);
    puts (string);
    return 0;
}

void del_spce (char * string)
{
    char ptr[MAX];
    int i;
    int j = 0;

    for (i = 0; *(string+ i) != '\0'; i++)
    {
        if (*(string + i) != ' ')
        {
            *(ptr + j) = *(string + i);
            j++;
        }
    }
    *(ptr + j) = '\0';
    strcpy (string, ptr);
}
void get_str (char * string)
{
    char * find;
    fgets (string, MAX, stdin);
    find = strchr (string, '\n');
    if (find)
        *find = '\0';
    else
        *(string + MAX - 1) = '\0';
}
