/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:14:40 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 10:14:42 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*pdst;
	const char	*psrc;

	pdst = (char *)dst;
	psrc = (char *)src;
	while (n > 0)
	{
		*pdst = (unsigned char)*psrc;
		n--;
		pdst++;
		if ((unsigned char)*psrc == (unsigned char)c)
			return (pdst);
		psrc++;
	}
	return (NULL);
}
