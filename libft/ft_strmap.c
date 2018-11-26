/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:51:29 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 10:51:31 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		len;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
		len++;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (*s)
	{
		new[len] = f(*s);
		len++;
		s++;
	}
	new[len] = '\0';
	return (new);
}
