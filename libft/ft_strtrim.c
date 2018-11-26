/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:52:26 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 10:52:28 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	char	*trimmed;
	int		len;
	int		last;

	if (!s)
		return (NULL);
	len = 0;
	last = 0;
	while (ft_is_snt_space(*s))
		s++;
	last = ft_find_last_char(s);
	if (!(trimmed = (char *)malloc(sizeof(char) * (last + 1 + 1))))
		return (NULL);
	while (len <= last)
	{
		trimmed[len] = s[len];
		len++;
	}
	trimmed[len] = '\0';
	return (trimmed);
}
