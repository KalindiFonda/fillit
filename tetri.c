/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 01:37:07 by kfonda            #+#    #+#             */
/*   Updated: 2018/11/28 01:37:11 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** 3(now size) because that is the max coordinate they can have within their 4*4
** tetramino map, but this function it's used also in the map so has to be size
*/

int		move_topleft(char (*tet_coord)[5][2], int size)
{
	int		min_x;
	int		min_y;
	int		c;

	min_x = size;
	min_y = size;
	c = 0;
	while (c < 4)
	{
		if (min_x > (*tet_coord)[c][0])
			min_x = (*tet_coord)[c][0];
		if (min_y > (*tet_coord)[c][1])
			min_y = (*tet_coord)[c][1];
		c++;
	}
	c = 0;
	while (c < 4)
	{
		(*tet_coord)[c][0] = (*tet_coord)[c][0] - min_x;
		(*tet_coord)[c][1] = (*tet_coord)[c][1] - min_y;
		c++;
	}
	return (1);
}

void	ft_movetetriright(char (*tetri)[5][2])
{
	int		i;

	i = -1;
	while (++i < 4)
		(*tetri)[i][0]++;
}

void	ft_movetetridown(char (*tet_coord)[5][2], int size)
{
	int		c;
	int		min_x;

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

void	ft_cleantetri(char ***map, char (*tetri)[5][2])
{
	int		i;

	i = -1;
	while (++i < 4)
		(*map)[(int)(*tetri)[i][1]][(int)(*tetri)[i][0]] = '.';
}
