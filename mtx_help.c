/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:02:48 by ggavryly          #+#    #+#             */
/*   Updated: 2018/11/27 15:02:56 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_mtx(t_liste *tr, char **mtx)
{
	int	i;
	int	j;
	int	k;
	int	**cord;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (mtx[0][k] == '\n')
				k++;
			tr->tetr[i][j] = (mtx[0][k] == '#') ? '#' : '.';
			j++;
			k++;
		}
		i++;
	}
	cord = ft_cord_tetr(tr);
	tr->cord = cord;
	tr->cords[0] = 0;
	tr->cords[1] = 0;
	tr->next = NULL;
}

int		map_count_mtx(char **map_mtx)
{
	int	i;

	i = 0;
	while (map_mtx[i])
		i++;
	return (i);
}

int		*ft_first_cord(t_liste *tetr, int *x, int *y)
{
	int i;
	int j;
	int	*first;

	i = 0;
	first = (int *)malloc(sizeof(int) * 2);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			(tetr->tetr[i][j] == '#') ? (((first[0] = i) == i) &&
				((first[1] = j) == j)
				&& (i = 3)
				&& (j = 4)) : j++;
		i++;
	}
	*x = first[0];
	*y = first[1];
	return (first);
}
