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
			//ft_free2d(map, len);
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
	if (tetri[0][0] < size && tetri[0][1] < size && tetri[1][0] < size &&
		tetri[1][1] < size && tetri[2][0] < size && tetri[2][1] < size && 
		tetri[3][0] < size && tetri[3][1] < size)
		return (1);
	return (0);
}

int ft_place(char ***map, char tetri[5][2], char let)
{
	int i;

	i = -1;
	if ((*map)[(int)tetri[0][0]][(int)tetri[0][1]] == '.' &&
		(*map)[(int)tetri[1][0]][(int)tetri[0][1]] == '.' &&
		(*map)[(int)tetri[2][0]][(int)tetri[2][1]] == '.' &&
		(*map)[(int)tetri[3][0]][(int)tetri[3][1]] == '.')
	{
		while (++i < 4)
			(*map)[(int)tetri[i][0]][(int)tetri[i][1]] = let;
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

void ft_movetetri(char (*tetri)[5][2], int down)
{
	int i;
	int k;

	i = -1;
	if (down)
		k = 1;
	else
		k = 0;
	printf("Before:%d\n", (*tetri)[i][down]);
	while (++i < 4)
		(*tetri)[i][down] += 1;
	printf("After:%d\n", (*tetri)[i][down]);
}

char **ft_solver(char **map, char tetri[26][5][2], int info[3])
{
	if (info[0] < info[1])
	{
		if (ft_inbounds(tetri[info[0]], info[2]))
		{
			if (ft_place(&map, tetri[info[0]], tetri[info[0]][4][0]))
			{
				info[0]++;
				return(map = ft_solver(map, tetri, info));
			}
			else
			{
				ft_movetetri(&tetri[info[0]], 0);
				return(map = ft_solver(map, tetri, info));
			}
		}
		else
		{
			ft_movetetri(&tetri[info[0]], 0);
			return(map = ft_solver(map, tetri, info));
		}
	}
	else
		return (map);
}
