/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:11:14 by ggavryly          #+#    #+#             */
/*   Updated: 2018/11/24 13:11:27 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		func_tmp(char ***mtx)
{
	int	ijc[3];

	ijc[0] = 0;
	while (ijc[0] < 4)
	{
		ijc[1] = 0;
		while (ijc[1] < 4)
		{
			ijc[2] = 0;
			if ((*mtx)[ijc[0]][ijc[1]] == '#')
			{
				if ((ijc[0] + 1) <= 3)
					ijc[2] += ((*mtx)[ijc[0] + 1][ijc[1]] != '.') ? 1 : 0;
				if ((ijc[0] - 1) >= 0)
					ijc[2] += ((*mtx)[ijc[0] - 1][ijc[1]] != '.') ? 1 : 0;
				if ((ijc[1] + 1) <= 3)
					ijc[2] += ((*mtx)[ijc[0]][ijc[1] + 1] != '.') ? 1 : 0;
				if ((ijc[1] - 1) >= 0)
					ijc[2] += ((*mtx)[ijc[0]][ijc[1] - 1] != '.') ? 1 : 0;
				(*mtx)[ijc[0]][ijc[1]] = (ijc[2]) ? (ijc[2] + 48) : 46;
			}
			ijc[1]++;
		}
		ijc[0]++;
	}
}

int				count_bound(char **mtx)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	func_tmp(&mtx);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (mtx[i][j] != '.')
				count += mtx[i][j] - 48;
			j++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (0);
	return (1);
}

char			*file_to_line(const char *name)
{
	int		fd;
	char	*file;
	char	*tmp;
	int		i;
	char	buf[BUFF_SIZE + 1];

	i = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
		return (NULL);
	file = ft_strnew(1);
	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		if (i < 0)
		{
			ft_memdel((void **)&file);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = ft_strjoin(file, buf);
		ft_memdel((void **)&file);
		file = tmp;
	}
	close(fd);
	return (file);
}
