#ifndef FT_H
# define FT_H
# define SIZE 4
#include <stdlib.h>
#include <unistd.h>

int    ft_solve(int **tab, int *rules, int index);
void    init_tab(int ***tab, int size);
void    print_tab(int **tab, int size);
int    ft_convert_rules(int **rules, char *str, int size);
int     test_col_ok(int test, int **tab, int index);
int     test_line_ok(int test, int **tab, int index);
int     tab_is_ok(int **tab, int *rules);
int     check_d_to_u(int **tab, int num_col, int *rules);
int     check_u_to_d(int **tab, int num_col, int *rules);
int     check_l_to_r(int **tab, int num_line, int *rules);
int     check_r_to_l(int **tab, int num_line, int *rules);

#endif