/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:37:59 by opishche          #+#    #+#             */
/*   Updated: 2018/11/28 20:27:25 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 1
# include <stdio.h>

typedef struct		s_liste
{
	int				**cord;
	int				cords[2];
	int				tetr[4][4];
	struct s_liste	*next;
	struct s_liste	*prev;
}					t_liste;

int					valid_file(char *text);

int					count_bound(char **mtx);

char				*file_to_line(const char *name);

char				**teterminos(char *text, char **result);

void				fill_mtx(t_liste *tr, char **mtx);

int					count_figure(char **tetr_mtx);

t_liste				*ft_tetrnew(char **tetr_mtx);

int					map_count_mtx(char **map_mtx);

char				**ft_sizeup(char **map, int n, t_liste *list);

int					**ft_cord_tetr(t_liste *tetr);

int					ft_set_elem(char ***map, int *xy, int **cord);

int					fill_elem(char ***m, int *x, t_liste *t, int **c);

int					ft_check_n(int **cord, char **map, int *xy);

int					**ft_memcord(void);

void				free_map(char **map);

int					fill_recursion(char ***map, t_liste *tetrl);

char				**ft_initialize(void);

void				print_map(char **map);

void				ft_nullcord(t_liste *thead);

void				ft_del_elem(char ***map, t_liste *tetr, int **cord);

char				**get_fig(char *str);

void				free_memcoord(int **coord);

void				ft_del_list(t_liste *thead);

int					*ft_first_cord(t_liste *t, int *x, int *y);

#endif
