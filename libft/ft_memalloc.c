/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:51:04 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 10:51:07 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	char	*area;
	int		i;

	i = 0;
	if (!(area = malloc(sizeof(char) * size)))
		return (NULL);
	while (size > 0)
	{
		area[i] = 0;
		i++;
		size--;
	}
	return (area);
}
