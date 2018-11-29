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
		while (ft_inbounds(tetri[info[0]], info[2]))
		{
			if (ft_place(map, tetri[info[0]], tetri[info[0]][4][0]))
			{
				info[0]++;
				if (!ft_solver(map, tetri, info))
					return (0);
				info[0]--;
				ft_cleantetri(map, &tetri[info[0]]);
			}
			ft_movetetriright(&tetri[info[0]]);
			if (!ft_inbounds(tetri[info[0]], info[2]))
				ft_movetetridown(&tetri[info[0]], info[2]);
		}
		return (move_topleft(&tetri[info[0]], info[2]));
	}
	return (0);
}
