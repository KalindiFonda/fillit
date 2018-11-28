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

int		print_error(void)
{
	ft_putendl_fd("error", 2);
	return (-1);
}

void	ft_printmap(char **map)
{
	int		x;

	x = -1;
	while (map[++x])
	{
		ft_putstr(map[x]);
		ft_putchar('\n');
	}
	exit(1);
}
