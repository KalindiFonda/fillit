/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:52:28 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 10:52:30 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**w_list;
	int		wc;
	int		len;
	int		w_len;

	len = 0;
	w_len = 0;
	wc = 0;
	if ((!s) || !(w_list = (char **)malloc(sizeof(char*) * \
		(ft_words_num(s, c) + 1))))
		return (NULL);
	while (*s != '\0' && wc < ft_words_num(s, c))
	{
		while ((s[len] == c) && (s[len] != '\0'))
			len++;
		w_len = -len;
		while ((s[len] != c) && (s[len] != '\0'))
			len++;
		if (!(ft_make_word(w_list, w_len + len, wc, s - w_len)))
			return (NULL);
		wc++;
		w_len = 0;
	}
	w_list[wc] = NULL;
	return (w_list);
}
