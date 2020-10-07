#include <stdio.h>
#include <string.h>
#define MAX 101
#define LIM 10

void get_str (char *);
void get_LIM_strs (char strings[LIM][MAX]);
void print_LIM_strs (char **, int);
char get_option ();
void sort_by_ASCII_order (char **, int);
void sort_by_strlen (char **, int);
void sort_by_initial_word (char **, int);
int initial_word_len (char *);

int main (void)
{
    char strings[LIM][MAX];
    char *ptr[LIM];
    int count;

    printf ("You choose %c.\n", get_option());
    get_LIM_strs (strings);
    for (count = 0; count < LIM && strings[count][0] != '\0'; count++)
        ptr[count] = strings[count];
    print_LIM_strs (ptr, count);
    sort_by_ASCII_order (ptr, count);
    print_LIM_strs (ptr, count);
    sort_by_strlen (ptr, count);
    print_LIM_strs (ptr, count);
    sort_by_initial_word (ptr, count);
    print_LIM_strs (ptr, count);

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

void get_LIM_strs (char strings[LIM][MAX])
{
    for (int i = 0; i < LIM; i++)
    {
        printf ("Please enter string No. %d:\n", i+1);
        get_str (*(strings + i));
        if (*(strings + i)[0] == '\0')
            break;
    }
}

void print_LIM_strs (char **strings, int count)
{
    puts ("Strings you enter are listed below:");
    for (int i = 0; i < count; i++)
        printf ("%d. %s\n", i + 1, *(strings + i));
}

void sort_by_ASCII_order (char **strings, int count)
{
    char *temp;
    int top, seek;

    for (top = 0; top < count - 1; top++)
        for (seek = top + 1; seek < count; seek++)
            if (strcmp (strings[top], strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}


void sort_by_strlen (char **strings, int count)
{
    char *temp;
    int top, seek;

    for (top = 0; top < count - 1; top++)
        for (seek = top + 1; seek < count; seek++)
            if (strlen (strings[top]) > strlen (strings[seek]))
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

int initial_word_len (char *string)
{
    int len = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ' && string[i] != '\t')
        {
            len++;
            if (string[i + 1] == ' ' || string[i + 1] == '\t')
                break;
        }
    }
    return len;
}

void sort_by_initial_word (char **strings, int count)
{
    char *temp;
    int top, seek;

    for (top = 0; top < count - 1; top++)
        for (seek = top + 1; seek < count; seek++)
            if (initial_word_len (strings[top]) > initial_word_len (strings[seek]))
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}
