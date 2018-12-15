/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:37:51 by opishche          #+#    #+#             */
/*   Updated: 2018/12/09 19:00:17 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**teterminos(char *text, char **result)
{
	unsigned int	i;
	unsigned int	j;
	int				count;

	count = ((ft_strlen(text) + 1) / 21) + 1;
	i = 0;
	j = 0;
	if (!(result = (char **)malloc(sizeof(char *) * count)))
		return (NULL);
	while ((int)i < (count - 1))
	{
		result[i] = ft_strsub(text, j, 20);
		j += 21;
		i++;
	}
	result[i] = NULL;
	return (result);
}

void	ft_nullcord(t_liste *thead)
{
	t_liste	*list;

	list = thead;
	while (list)
	{
		list->cords[0] = 0;
		list->cords[1] = 0;
		list = list->next;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map[i]);
		free(map);
	}
}

char	**ft_initialize(void)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	i = 0;
	map = (char **)malloc(sizeof(char *) * 3);
	while (j < 2)
	{
		if ((map[j] = (char *)malloc(sizeof(char) * 3)))
		{
			i = 0;
			while (i < 2)
			{
				map[j][i] = '.';
				i++;
			}
			map[j][i] = '\0';
		}
		j++;
	}
	map[j] = NULL;
	return (map);
}

int		**ft_memcord(void)
{
	int		i;
	int		**coord;

	i = 0;
	if (!(coord = (int **)malloc(sizeof(int *) * 5)))
		return (NULL);
	while (i < 4)
	{
		if (!(coord[i] = (int *)malloc(sizeof(int) * 2)))
			return (NULL);
		i++;
	}
	coord[i] = NULL;
	return (coord);
}
