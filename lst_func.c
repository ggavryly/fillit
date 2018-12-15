/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:41:57 by ggavryly          #+#    #+#             */
/*   Updated: 2018/11/27 13:42:49 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_liste		*ft_tetrnew(char **tetr_mtx)
{
	t_liste		*tmp;
	t_liste		*prev;
	t_liste		*alst;
	int			j;

	j = 0;
	prev = NULL;
	while (*tetr_mtx)
	{
		if ((tmp = (t_liste *)malloc(sizeof(t_liste))))
			fill_mtx(tmp, tetr_mtx);
		if (prev)
		{
			prev->next = tmp;
			tmp->prev = prev;
		}
		if (j++ == 0)
		{
			tmp->prev = NULL;
			alst = tmp;
		}
		prev = tmp;
		tetr_mtx++;
	}
	return (alst);
}

char		**get_fig(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**fig;

	i = 0;
	k = 0;
	fig = (char **)malloc(sizeof(char *) * 5);
	while (i < 4)
	{
		j = 0;
		if (str[k] == '\n')
			k++;
		fig[i] = (char *)malloc(sizeof(char) * 5);
		while (j < 4)
		{
			fig[i][j] = str[k++];
			j++;
		}
		fig[i][j] = '\0';
		i++;
	}
	fig[i] = NULL;
	return (fig);
}

char		**ft_sizeup(char **map, int n, t_liste *list)
{
	int		i;
	int		j;
	char	**mak;

	i = 0;
	mak = NULL;
	free_map(map);
	mak = (char **)malloc(sizeof(char *) * (n + 1));
	while (i < n)
	{
		j = 0;
		if ((mak[i] = (char *)malloc(sizeof(char) * (n + 1))))
		{
			while (j < n)
			{
				mak[i][j] = '.';
				j++;
			}
			mak[i][j] = '\0';
		}
		i++;
	}
	mak[i] = NULL;
	ft_nullcord(list);
	return (mak);
}

void		free_memcoord(int **coord)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		free(coord[i]);
		i++;
	}
	free(coord);
}

int			**ft_cord_tetr(t_liste *tetr)
{
	int	**coord;
	int	i;
	int	j;
	int	*first;
	int	k;

	k = 0;
	coord = ft_memcord();
	first = ft_first_cord(tetr, &i, &j);
	while (i < 4)
	{
		while (j < 4)
		{
			if (tetr->tetr[i][j] == '#')
			{
				coord[k][0] = i - first[0];
				coord[k++][1] = j - first[1];
			}
			if ((j == 3) && (((j == 3) ? (j = 0) : j) || 1))
				break ;
			j++;
		}
		i++;
	}
	return (coord);
}
