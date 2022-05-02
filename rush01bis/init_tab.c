#include <stdlib.h>

void    init_tab(int ***tab, int size)
{
    int     i;
    int     j;

    i = 0;
    *tab = malloc(sizeof(int *) * size);
    if (!*tab)
        return ;
    while (i < size)
    {
        (*tab)[i] = malloc(sizeof(int) * size);
        if (!((*tab)[i]))
            return ;
        i++;
    }
    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            ((*tab)[i])[j] = 0;
            j++;
        }
        i++;
    }
}