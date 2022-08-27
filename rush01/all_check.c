#include "ft.h"

int     check_r_to_l(int **tab, int num_line, int *rules)
{
    int     count;
    int     i;
    int     max;

    i = 0;
    count = 1;
    max = tab[num_line][0];
    while (i < SIZE)
    {
        if (tab[num_line][i] > max)
        {
            max = tab[num_line][i];
            count++;
        }
        i++;
    }
    if (count == rules[SIZE * 2 + num_line])
        return (1);
    return (0);
}

int     check_l_to_r(int **tab, int num_line, int *rules)
{
    int     count;
    int     i;
    int     max;

    i = SIZE - 1;
    count = 1;
    max = tab[num_line][SIZE - 1];
    while (i >= 0)
    {
        if (tab[num_line][i] > max)
        {
            max = tab[num_line][i];
            count++;
        }
        i--;
    }
    if (count == rules[SIZE * 3 + num_line])
        return (1);
    return (0);
}

int     check_u_to_d(int **tab, int num_col, int *rules)
{
    int     count;
    int     i;
    int     max;

    i = 0;
    count = 1;
    max = tab[i][num_col];
    while (i < SIZE)
    {
        if (tab[i][num_col] > max)
        {
            max = tab[i][num_col];
            count++;
        }
        i++;
    }
    if (count == rules[num_col])
        return (1);
    return (0);
}

int     check_d_to_u(int **tab, int num_col, int *rules)
{
    int     count;
    int     i;
    int     max;

    i = SIZE - 1;
    count = 1;
    max = tab[SIZE - 1][num_col];
    while (i >= 0)
    {
        if (tab[i][num_col] > max)
        {
            max = tab[i][num_col];
            count++;
        }
        i--;
    }
    if (count == rules[SIZE + num_col])
        return (1);
    return (0);
}

int     tab_is_ok(int **tab, int *rules)
{
    int     i;

    i = 0;
    while (i < SIZE * SIZE)
    {
        if (!check_l_to_r(tab, i / SIZE, rules)
        || !check_r_to_l(tab, i / SIZE, rules)
        || !check_u_to_d(tab, i % SIZE, rules)
        || !check_d_to_u(tab , i % SIZE, rules))
        return (0);
        i ++;
    }
    return (1);
}

int     test_line_ok(int test, int **tab, int index)
{
    int     i;

    i = 0;
    while (i < index % SIZE)
    {
        if (test == tab[index / SIZE][i])
            return (0);
        i++;
    }
    return (1);
}

int     test_col_ok(int test, int **tab, int index)
{
    int     i;

    i = 0;
    while (i < index / SIZE)
    {
        if (test == tab[i][index % SIZE])
            return (0);
        i++;
    }
    return (1);
}