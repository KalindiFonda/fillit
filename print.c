/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 01:32:27 by kfonda            #+#    #+#             */
/*   Updated: 2018/11/28 01:32:28 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		print_error(int i)
{
	if (i == 0)
		ft_putendl("usage: fillit file");
	if (i == -1)
		ft_putendl("error");
	return (-1);
}

void	ft_printmap(char **map, int size)
{
	int		x;

	x = -1;
	while (++x < size)
	{
		ft_putstr(map[x]);
		ft_putchar('\n');
	}
}
