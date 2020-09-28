#include <stdio.h>
#include <string.h>
#define MAX 100
char * find_char_in_str (char *, char);

int main (void)
{
    char c;
    char string[MAX];
    char * ptr;
    char * find;

    puts ("Please enter a string.");
    fgets (string, MAX, stdin);
    find = strchr (string, '\n');
    if (find)
        *find = '\0';
    puts ("Please enter a char to search.");
    c = getchar();
    ptr = find_char_in_str (string, c);
    if (ptr)
        printf ("The first char %c in %s starts from %s.\n",
                c, string, ptr);
    else
        printf ("Find no char %c in %s.\n",
                c, string);
    return 0;
}

char * find_char_in_str (char * string, char c)
{
    char * ptr;
    for (int count = 0; count < MAX && *(string + count) != '\n'; count++)
    {
        if (*(string + count) == c)
        {
            ptr = string + count;
            return ptr;
            break;
        }
    }
    return NULL;
}
