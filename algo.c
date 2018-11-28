/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 00:10:29 by skunz             #+#    #+#             */
/*   Updated: 2018/11/26 00:10:59 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //clear

void ft_printcords(char tetri[5][2])
{
	for (int i = 0; i < 4; i++)
	{
		printf("#%d\n", i);
		printf("Tetri X:%d\n", tetri[i][0]);
		printf("Tetri Y:%d\n", tetri[i][1]);
	}
}

int ft_getminmapsize(int tetricount)
{
	int square;

	square = 1;
	while (square * square < tetricount * 4)
		square++;
	return (square);
}

char **ft_setmap(int size) //needs cleanup if second malloc fails
{
	char **map;
	int i;

	i = -1;
	if (!(map = malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (++i < size)
	{
		if (!(map[i] = malloc(sizeof(char) * (size + 1))))
		{
			//ft_free2d(map, size);
			return (NULL);
		}
		map[i][size] = '\0';
	}
	map[size] = NULL;
	return (map);
}

void ft_mapinitalise(char **map, int size)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++x < size)
	{
		while (++y < size)
			map[x][y] = '.';
		y = -1;
	}
}

char **ft_increasemap(char **map, int size) //free map correct?
{
	char **new;
	int x;
	int y;

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

int ft_inbounds(char tetri[5][2], int size)
{
	if (tetri[0][0] < size && tetri[0][1] < size &&
		tetri[1][0] < size && tetri[1][1] < size &&
		tetri[2][0] < size && tetri[2][1] < size &&
		tetri[3][0] < size && tetri[3][1] < size)
		return (1);
	return (0);
}

int ft_inboundsy(char tetri[5][2], int size)
{
	if (tetri[0][1] < size && tetri[1][1] < size &&
		tetri[2][1] < size && tetri[3][1] < size)
		return (1);
	return (0);
}

int ft_place(char ***map, char tetri[5][2], char let)
{
	int i;

	i = -1;
	if ((*map)[(int)tetri[0][1]][(int)tetri[0][0]] == '.' &&
		(*map)[(int)tetri[1][1]][(int)tetri[1][0]] == '.' &&
		(*map)[(int)tetri[2][1]][(int)tetri[2][0]] == '.' &&
		(*map)[(int)tetri[3][1]][(int)tetri[3][0]] == '.')
	{
		while (++i < 4)
			(*map)[(int)tetri[i][1]][(int)tetri[i][0]] = let;
		return (1);
	}
	return (0);
	
}

void	ft_printmap(char **map)
{
	int x;

	x = -1;
	while (map[++x])
	{
		ft_putstr(map[x]);
		ft_putchar('\n');
	}
}

void ft_movetetriright(char (*tetri)[5][2])
{
	int i;

	i = -1;
	while (++i < 4)
		(*tetri)[i][0]++;
}

void ft_movetetridown(char (*tet_coord)[5][2], int size)
{
	int c;
	int min_x;

	min_x = size;
	c = -1;
	while (++c < 4)
	{
		if (min_x > (*tet_coord)[c][0])
			min_x = (*tet_coord)[c][0];
	}
	c = -1;
	while (++c < 4)
	{
		(*tet_coord)[c][0] -= min_x;
		(*tet_coord)[c][1]++;
	}
}

void ft_cleantetri(char ***map, char (*tetri)[5][2])
{
	int i;

	i = -1;
	while (++i < 4)
		(*map)[(int)(*tetri)[i][1]][(int)(*tetri)[i][0]] = '.';
}

int ft_solver(char ***map, char tetri[26][5][2], int info[3])
{
	if (info[0] < info[1])
	{
		if (ft_inbounds(tetri[info[0]], info[2]))
		{
			if (ft_place(map, tetri[info[0]], tetri[info[0]][4][0]))
			{
				info[0]++;
				ft_solver(map, tetri, info);
			}
			else
			{
				ft_movetetriright(&tetri[info[0]]);
				ft_solver(map, tetri, info);
			}
		}
		else
		{
			if (!ft_inboundsy(tetri[0], info[2]))
				return (0);
			if (!ft_inboundsy(tetri[info[0]], info[2]))
			{
				move_topleft(&tetri[info[0]], info[2]);
				info[0]--;
				ft_cleantetri(map, &tetri[info[0]]);
				ft_movetetriright(&tetri[info[0]]);
				ft_solver(map, tetri, info);
			}
			ft_movetetridown(&tetri[info[0]], info[2]);
			ft_solver(map, tetri, info);
		}
	}
	return (1);
}
