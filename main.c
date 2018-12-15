/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:38:33 by opishche          #+#    #+#             */
/*   Updated: 2018/11/22 17:38:36 by opishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int ar, char **av)
{
	t_liste		*list;
	char		**map;
	char		*text;

	if (ar != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	text = file_to_line(av[1]);
	map = NULL;
	if ((valid_file(text)))
	{
		ft_putstr("error\n");
		return (0);
	}
	list = ft_tetrnew(teterminos(text, NULL));
	free(text);
	map = ft_initialize();
	fill_recursion(&map, list);
	print_map(map);
	return (0);
}
