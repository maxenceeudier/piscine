#include "ft.h"

int    ft_solve(int **tab, int *rules, int index)
{
    int     test;

    if (index == SIZE * SIZE && tab_is_ok(tab, rules))
    {
        print_tab(tab, SIZE);
        return (1);
    } 
    if (index < SIZE * SIZE)
    {
        test = 1;
        while (test <= SIZE )
        {
            if (test_line_ok(test, tab, index) && test_col_ok(test, tab, index))
            {
                tab[index / SIZE][index % SIZE] = test;
                if (ft_solve(tab, rules, index + 1))
                    return (1);
            }
            test++;
        }
    }
    return (0);
}