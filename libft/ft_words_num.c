/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:52:36 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 14:52:38 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_words_num(char const *s, char c)
{
	int		word_count;
	int		count;

	count = 1;
	word_count = 0;
	while (*s)
	{
		if (*s != c && count == 1)
		{
			word_count++;
			count = 0;
		}
		if (*s == c && count == 0)
			count = 1;
		s++;
	}
	return (word_count);
}
