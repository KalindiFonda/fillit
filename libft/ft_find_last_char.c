/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_last_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:52:25 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 14:52:28 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_find_last_char(char const *s)
{
	int		len;
	int		last;

	len = 0;
	last = 0;
	while (s[len] != '\0')
	{
		if (!(ft_is_snt_space(s[len])))
			last = len;
		len++;
	}
	return (last);
}
