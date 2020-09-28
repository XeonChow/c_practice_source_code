#include <stdio.h>
#define MAX 100
void get_n_char (char *, unsigned int);

int main (void)
{
    int n = 10;
    char string[MAX];
    puts ("Type some text. ");
    get_n_char(string, n);
    puts (string);
    return 0;
}

void get_n_char (char * string, unsigned int n)
{
    ;
    for (int count = 0; count < n; count++)
    {
        * (string + count) = getchar ();
        if (* (string + count) == '\n' || * (string + count) == '\t' || * (string + count) == ' ')
        {
            * (string + count) = '\0';
            break;
        }
    }
    * (string + n) = '\0';
/*    while ((*(string + count) = getchar ()) != '\n' && count < n)
    {
        count++;
    }
    string[n] = '\0'; */
}
