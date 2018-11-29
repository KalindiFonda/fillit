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

int		ft_inbounds(char tetri[5][2], int size)
{
	if (tetri[0][0] < size && tetri[0][1] < size &&
		tetri[1][0] < size && tetri[1][1] < size &&
		tetri[2][0] < size && tetri[2][1] < size &&
		tetri[3][0] < size && tetri[3][1] < size)
		return (1);
	return (0);
}

int		ft_inboundsy(char tetri[5][2], int size)
{
	if (tetri[0][1] < size && tetri[1][1] < size &&
		tetri[2][1] < size && tetri[3][1] < size)
		return (1);
	return (0);
}

int		ft_place(char ***map, char tetri[5][2], char let)
{
	int		i;

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

int		ft_solver(char ***map, char tetri[26][5][2], int info[3])
{
	if (info[0] < info[1])
	{
		// ft_printmap(*map, info[2]);
		// printf("\n");
		if (ft_inbounds(tetri[info[0]], info[2]))
		{

			if (ft_place(map, tetri[info[0]], tetri[info[0]][4][0]))
				info[0]++;
			else
			{
				//printf("right: %d\n", info[2]);
				ft_movetetriright(&tetri[info[0]]);
			}
			return (ft_solver(map, tetri, info)); // took this out of the brackets
		}
		else
		{
			//printf("xx\n");
			if (!ft_inboundsy(tetri[0], info[2]))
			{
				move_topleft(&tetri[0], info[1]);
				return (1);
			}
			if (!ft_inboundsy(tetri[info[0]], info[2]))
			{
				//printf("rip y\n");
				move_topleft(&tetri[info[0]], info[1]);// what does this do?
				//printf("#%d\n", info[0]);
				//ft_printcords(tetri[info[0]]);
				info[0]--;
				//printf("#%d\n", info[0]);
				//ft_printcords(tetri[info[0]]);
				ft_cleantetri(map, &tetri[info[0]]);
				ft_movetetriright(&tetri[info[0]]);
				return (ft_solver(map, tetri, info));
			}
			ft_movetetridown(&tetri[info[0]], info[2]);
			return (ft_solver(map, tetri, info));
		}
	}
	return (0);
}
