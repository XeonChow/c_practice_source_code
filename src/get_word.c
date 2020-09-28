#include <stdio.h>
#define MAX 100
void get_word (char *);

int main (void)
{
    char string[MAX];

    puts ("Type some text and I'll return the first word. ");
    get_word(string);
    puts (string);

    return 0;
}

void get_word (char * string)
{
    char c;
    int count = 0;
    while ((c = getchar()) != '\n')
    {
        if ((c == '\t' || c == ' ') && count != 0)
            break;
        else if (c != '\t' && c != ' ')
        {
            *(string + count) = c;
            count ++;
        }
        else
            continue;
    }
}
