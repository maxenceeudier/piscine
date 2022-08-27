#include <stdlib.h>

int    ft_convert_rules(int **rules, char *str, int size)
{
    int     i;
    int     j;

    *rules = malloc(sizeof(int) * (size * 4));
    if (!*rules)
        return (0);
    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] <= size + '0' && str[i] >= '0' && j < (size * 4))
        {
            (*rules)[j] = str[i] - '0';
            j++;
            i++;
        }
        else if (str[i] == ' ')
            i++;
        else
            return (0);
    }
    if (j != size * 4 || i != (size * 4 - 1) * 2 + 1)
        return (0);
    return (1);
}