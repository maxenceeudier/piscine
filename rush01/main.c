#include "ft.h"

int main(int ac, char **av)
{
    int     **tab;
    int     *rules;

    if (ac == 2)
    {
        init_tab(&tab, SIZE);
        if (!ft_convert_rules(&rules, av[1], SIZE))
        {
            write (1, "error data", 10);
            return (0);
        }
        ft_solve(tab, rules, 0);
    }
    return (0);
}


