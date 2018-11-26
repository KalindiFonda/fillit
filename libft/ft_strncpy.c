/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:18:33 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 10:18:39 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*pdest;

	pdest = dest;
	while (*src != '\0' && n > 0)
	{
		*pdest = *src;
		src++;
		pdest++;
		n--;
	}
	while (n > 0)
	{
		*pdest = '\0';
		pdest++;
		n--;
	}
	return (dest);
}
