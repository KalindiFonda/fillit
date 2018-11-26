/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:52:24 by kfonda            #+#    #+#             */
/*   Updated: 2018/11/16 13:06:56 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(new_str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	len = 0;
	while (*s1)
	{
		new_str[len] = *s1;
		s1++;
		len++;
	}
	while (*s2)
	{
		new_str[len] = *s2;
		s2++;
		len++;
	}
	new_str[len] = '\0';
	return (new_str);
}
