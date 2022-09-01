/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:15:35 by meudier           #+#    #+#             */
/*   Updated: 2022/03/28 18:33:51 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_data
{
	int		num_max;
	int		born_sup;
	int		born_inf;
	int		x;
	int		y;
	char	vide;
	char	obstacle;
	char	plein;
}	t_data;

int		ft_solver(char **big, char **mini, t_data *p);
int		char_is_charset(char c, char *charset);
int		ft_get_number_of_words(char *str, char *charset);
char	*ft_get_word(int *index, char *str, char *charset);
char	**ft_split(char *str, char *charset);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		size_line(char **map);
int		the_smaller(int a, int b);
t_data	*ft_create_data(char *file, int num_col_max);
char	*ft_get_file(char *file_to_read);
int		get_data_and_map(char *file_name, char ***map, t_data **data);
char	**create_mini(int size);
char	*ft_strdup(char *src);
int		ft_check_file(char **map, t_data *data);
char	*ft_read_stdin(void);
int		ft_error(void);
void	ft_print_big(char **big);
void	ft_free(char **mini, char **big, t_data *data);
void	ft_init(char ***mini, char ***big, t_data **data);
void	init_i_and_av(int ac, int *i, char ***av);
int		ft_init_stuff(char **mini, int *i);
void	ft_plusplus(int *a, int *b, int *c, int *d);
#endif
