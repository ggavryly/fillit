/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:38:43 by ggavryly          #+#    #+#             */
/*   Updated: 2018/11/29 16:38:50 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_liste		*recu_help(t_liste *t, int *n, char ***map)
{
	if (!t->prev)
	{
		*map = ft_sizeup(*map, (*n) + 1, t);
		(*n)++;
	}
	else
	{
		ft_del_elem(map, t->prev, t->prev->cord);
		t->cords[0] = 0;
		t->cords[1] = 0;
		t = t->prev;
		if (t->cords[1] < (*n) - 1)
			t->cords[1]++;
		else if (t->cords[1] == (*n) - 1)
		{
			t->cords[0]++;
			t->cords[1] = 0;
		}
	}
	return (t);
}

int					fill_recursion(char ***map, t_liste *tetrl)
{
	int	n;

	n = 2;
	while (tetrl)
	{
		if (!(fill_elem(map, tetrl->cords, tetrl, tetrl->cord)))
		{
			if ((tetrl->cords[0] == n - 1) && (tetrl->cords[1] == n - 1))
				tetrl = recu_help(tetrl, &n, map);
			else if (tetrl->cords[1] == n - 1)
			{
				tetrl->cords[0]++;
				tetrl->cords[1] = 0;
			}
			else if (tetrl->cords[0] < n && tetrl->cords[1] < n)
				tetrl->cords[1]++;
			continue ;
		}
		else
			tetrl = tetrl->next;
	}
	return (1);
}
