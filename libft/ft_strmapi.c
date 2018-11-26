/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:51:32 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 10:51:36 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	len;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
		len++;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (s[len])
	{
		new[len] = f(len, s[len]);
		len++;
	}
	new[len] = '\0';
	return (new);
}
