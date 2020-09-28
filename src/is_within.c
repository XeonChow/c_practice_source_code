#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100
bool is_within (char *, char);
void get_input (char *, char *);
char get_command ();

int main (void)
{
    char c;
    char string[MAX];
    bool flag;
    char * find;

    puts ("This program helps you to find out if a charater is within a string.");
    puts ("Type y to start and q to quit.");
    while (get_command () != 'q')
    {
        get_input (string, &c);
        flag = is_within (string, c);
        if (flag)
            printf ("'%c' is found in \"%s\".\n", c, string);
        else
            printf ("No '%c' is found in \"%s\".\n", c, string);
        puts ("Type y to start and q to quit.");
    }
    return 0;
}

char get_command ()
{
    char c = getchar ();
    while (getchar () != '\n')
        continue;
    while (c != 'y' && c != 'q')
    {
        printf ("%c is not a valid command, enter y to start and q to quit.", c);
        c = getchar ();
        while (getchar () != '\n')
            continue;
    }
    return c;
}

bool is_within (char * string, char c)
{
    for (int count = 0; count < MAX && *(string + count) != '\0'; count++)
    {
        if (*(string + count) == c)
        {
            return true;
            break;
        }
    }
    return false;
}

void get_input (char * string, char * c)
{
    char * find;
    puts ("Please enter a string.");
    fgets (string, MAX, stdin);
    find = strchr (string, '\n');
    if (find)
        *find = '\0';
    puts ("Please enter the characters to find.");
    *c = getchar ();
    while (getchar () != '\n')
        continue;
}
