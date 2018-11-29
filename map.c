/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 01:34:34 by kfonda            #+#    #+#             */
/*   Updated: 2018/11/28 01:34:36 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_getminmapsize(int tetricount)
{
	int		square;

	square = 1;
	while (square * square < tetricount * 4)
		square++;
	return (square);
}

char	**ft_setmap(int size)
{
	char	**map;
	int		i;

	i = -1;
	if (!(map = malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (++i < size)
	{
		if (!(map[i] = malloc(sizeof(char) * (size + 1))))
		{
			ft_free2d(map, size);
			return (NULL);
		}
		map[i][size] = '\0';
	}
	map[size] = NULL;
	return (map);
}

void	ft_mapinitalise(char **map, int size)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (++x < size)
	{
		while (++y < size)
			map[x][y] = '.';
		y = -1;
	}
}

char	**ft_increasemap(char **map, int size)
{
	char	**new;
	int		x;
	int		y;

	new = ft_setmap(size + 1);
	x = -1;
	y = -1;
	while (++x < size)
	{
		while (++y < size)
			new[x][y] = map[x][y];
		free(map[x]);
		y = -1;
	}
	x = -1;
	while (++y < size)
		new[y][size] = '.';
	while (++x <= size)
		new[size][x] = '.';
	free(map);
	return (new);
}
