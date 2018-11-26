/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:14:43 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 10:14:46 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*pdst;
	const char		*psrc;

	pdst = (char *)dst;
	psrc = (char *)src;
	if (pdst <= psrc)
	{
		while (len)
		{
			*pdst++ = *psrc++;
			len--;
		}
	}
	else
	{
		pdst += len - 1;
		psrc += len - 1;
		while (len)
		{
			*pdst-- = *psrc--;
			len--;
		}
	}
	return (dst);
}
