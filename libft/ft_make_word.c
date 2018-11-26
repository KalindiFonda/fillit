/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:52:41 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 14:52:43 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_make_word(char **w_list, int w_len, int wc, const char *s)
{
	int		i;

	i = 0;
	if (!(w_list[wc] = (char *)malloc(sizeof(char) * (w_len + 1))))
		return (0);
	while (i < w_len)
	{
		w_list[wc][i] = s[i];
		i++;
	}
	w_list[wc][i] = '\0';
	return (1);
}
