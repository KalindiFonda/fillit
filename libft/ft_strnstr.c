/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:15:19 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 10:15:22 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t		j;
	size_t		find_len;

	j = 0;
	find_len = ft_strlen(find);
	if (find[j] == '\0')
		return ((char *)str);
	while (str[j] != '\0' && (j + find_len) <= len)
	{
		if (ft_strncmp(str + j, find, find_len) == 0)
		{
			return ((char *)str + j);
		}
		j++;
	}
	return (NULL);
}
