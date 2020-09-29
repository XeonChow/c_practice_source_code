#include <stdio.h>
#include <string.h>
#define MAX 101
#define LIM 10

void get_str (char *);
void get_LIM_strs (char **);
void print_LIM_strs (char **);
char get_option ();

int main (void)
{
    char strings[LIM][MAX];

    get_LIM_strs (strings);
    print_LIM_strs (strings);

    return 0;

}


char get_option ()
{
    char option;
    puts ("Options are listed below:");
    puts ("a. Print strings entered.");
    puts ("b. Sort strings by ASCII.");
    puts ("c. Sort strings by string length.");
    puts ("d. Sort strings by length of the first word in string.");
    puts ("q. Quit.");
    option = getchar ();
    while (getchar () != '\n')
        continue;
    while (option != 'a' && option != 'b' && option != 'c'
            && option != 'd' && option != 'q')
    {
        printf ("%c is not allowed, options are listed below:\n", option);
        puts ("a. Print strings entered.");
        puts ("b. Sort strings by ASCII.");
        puts ("c. Sort strings by string length.");
        puts ("d. Sort strings by length of the first word in string.");
        puts ("q. Quit.");
        option = getchar ();
        while (getchar () != '\n')
            continue;
    }
    return option;
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

void get_LIM_strs (char ** strings)
{
    for (int i = 0; i < LIM; i++)
    {
        printf ("Please enter string No. %d:\n", i+1);
        get_str (*(strings + i));
        if (*(strings + i)[0] == '\0')
            break;
    }
}

void print_LIM_strs (char ** strings)
{
    puts ("Strings you enter are listed below:");
    for (int i = 0; i < LIM; i++)
    {
        if (*(strings + i)[0] == '\0')
            printf ("%d. %s\n", i + 1, *(strings + i));
    }
}
