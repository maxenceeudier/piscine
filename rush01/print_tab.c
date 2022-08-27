#include <unistd.h>

void    print_tab(int **tab, int size)
{
    int     i;
    int     j;
    char    temp;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            temp = tab[i][j] + '0';
            write (1, &temp, 1);
            j++;
        }
        write (1, "\n", 1);
        i++;
    }
}