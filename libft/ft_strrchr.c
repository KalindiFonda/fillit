/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:12:33 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 10:12:50 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		last;

	i = 0;
	last = -1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			last = i;
		i++;
	}
	if (c == '\0')
		return ((char *)(str + i));
	if (last == -1)
		return (NULL);
	return ((char *)(str + last));
}
