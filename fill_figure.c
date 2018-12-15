/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_it.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:27:54 by opishche          #+#    #+#             */
/*   Updated: 2018/11/28 17:27:57 by opishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char g_s = 'A';

int		ft_check_n(int **find, char **map, int *xy)
{
	int	counter;
	int	n;
	int	i[2];

	counter = 0;
	i[0] = xy[0];
	i[1] = xy[1];
	n = map_count_mtx(map);
	if (i[0] + find[1][0] >= 0 && i[0] + find[1][0] <= n - 1
		&& i[1] + find[1][1] >= 0 && i[1] + find[1][1] <= n - 1)
		if (map[i[0] + find[1][0]][i[1] + find[1][1]] == '.')
			counter++;
	if (i[0] + find[2][0] >= 0 && i[0] + find[2][0] <= n - 1
		&& i[1] + find[2][1] >= 0 && i[1] + find[2][1] <= n - 1)
		if (map[i[0] + find[2][0]][i[1] + find[2][1]] == '.')
			counter++;
	if (i[0] + find[3][0] >= 0 && i[0] + find[3][0] <= n - 1
		&& i[1] + find[3][1] >= 0 && i[1] + find[3][1] <= n - 1)
		if (map[i[0] + find[3][0]][i[1] + find[3][1]] == '.')
			counter++;
	if (counter != 3)
		return (0);
	return (1);
}

int		ft_set_elem(char ***map, int *xy, int **cord)
{
	int		x;
	int		y;
	int		yes;

	if ((*map)[xy[0]][xy[1]] != '.')
		return (0);
	yes = ft_check_n(cord, *map, xy);
	x = xy[0];
	y = xy[1];
	if (yes)
	{
		(*map)[x][y] = g_s;
		(*map)[x + cord[1][0]][y + cord[1][1]] = g_s;
		(*map)[x + cord[2][0]][y + cord[2][1]] = g_s;
		(*map)[x + cord[3][0]][y + cord[3][1]] = g_s;
		g_s++;
		return (1);
	}
	return (0);
}

int		fill_elem(char ***map, int *xy, t_liste *tetr, int **cord)
{
	if (ft_set_elem(map, xy, cord))
	{
		tetr->cords[0] = xy[0];
		tetr->cords[1] = xy[1];
		return (1);
	}
	tetr->cords[0] = xy[0];
	tetr->cords[1] = xy[1];
	return (0);
}

void	ft_del_elem(char ***map, t_liste *tetr, int **cord)
{
	int xy[2];

	xy[0] = tetr->cords[0];
	xy[1] = tetr->cords[1];
	(*map)[cord[0][0] + xy[0]][cord[0][1] + xy[1]] = '.';
	(*map)[cord[1][0] + xy[0]][cord[1][1] + xy[1]] = '.';
	(*map)[cord[2][0] + xy[0]][cord[2][1] + xy[1]] = '.';
	(*map)[cord[3][0] + xy[0]][cord[3][1] + xy[1]] = '.';
	g_s--;
}
