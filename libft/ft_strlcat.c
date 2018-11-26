/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:15:07 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 10:15:09 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	len;
	size_t	out_len;
	size_t	i;

	i = 0;
	len = 0;
	out_len = 0;
	while (dest[len] != '\0')
		len++;
	while (src[out_len] != '\0')
		out_len++;
	dest = dest + len;
	while (src[i] != '\0' && (size > 1 + len + i))
	{
		*dest = src[i];
		dest++;
		i++;
	}
	*dest = '\0';
	if (size > len)
		size = len;
	return (size + out_len);
}
