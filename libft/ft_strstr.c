/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:15:16 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 10:15:18 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *str, const char *find)
{
	int		j;

	j = 0;
	if (find[0] == '\0')
		return ((char *)str);
	while (*str != '\0')
	{
		if (*str == find[j])
		{
			while (find[j] != '\0' && str[j] != '\0' && str[j] == find[j])
				j++;
			if (find[j] == '\0')
				return ((char *)str);
		}
		j = 0;
		str++;
	}
	return (NULL);
}
