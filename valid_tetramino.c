/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Valid_Tetramino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:49:19 by ggavryly          #+#    #+#             */
/*   Updated: 2018/11/16 14:49:40 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		first_stage(const char *str)
{
	int		i;
	int		s;
	int		f;

	i = 0;
	s = 0;
	f = 0;
	while (str[i])
	{
		while ((str[i] == '.' || str[i] == '#') && s++ < 4)
			i++;
		if (str[i++] == '\n' && s == 4 && str[i])
		{
			s = 0;
			f++;
			if (f == 4 && str[i++] == '\n')
				f = 0;
			else if (str[i] == '\n')
				return (1);
		}
		else if (str[i - 1] != '\n')
			return (1);
	}
	return (0);
}

static int		second_stage(char *str)
{
	int		i;
	int		count_e;
	int		count_f;
	int		k;

	k = 0;
	i = 0;
	count_e = 0;
	count_f = 0;
	while (str[i])
	{
		if (str[i] == '#')
			count_f++;
		else if (str[i] == '.')
			count_e++;
		if (str[i] == '\n' && str[i + 1] == '\n')
			k++;
		i++;
	}
	if (count_f == 4 * (k + 1) && count_e == 12 * (k + 1) && k < 27)
		return (0);
	return (1);
}

static int		third_stage(char *str)
{
	int		i;
	char	**mtx;
	int		err;
	int		f;

	err = 0;
	i = 0;
	f = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if ((str[i] == '\n' && (str[i + 1] == '\n')) || !f)
		{
			mtx = get_fig(str + i + f);
			err += count_bound(mtx);
			free_map(mtx);
		}
		f = 1;
		i++;
	}
	return (err);
}

int                valid_file(char *text)
{
    int        e;
    
    if (text)
    {
        e = 0;
        e += first_stage(text);
        e += second_stage(text);
        e += third_stage(text);
        if (e)
            return (1);
        return (0);
    }
    return (1);
}
