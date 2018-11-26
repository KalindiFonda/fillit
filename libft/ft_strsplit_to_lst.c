/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_to_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:46:19 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/25 09:46:21 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_strsplit_to_lst(char const *s, char c)
{
	t_list	*p_list;
	int		len;
	int		i;
	char	*w;

	len = 0;
	if (!s)
		return (NULL);
	while (ft_words_num(s + len, c) > 0 && s[len] != '\0')
	{
		while ((*s == c) && (*s != '\0'))
			s++;
		len = 0;
		while ((s[len] != c) && (s[len] != '\0'))
			len++;
		w = (char *)malloc(sizeof(char) * (len + 1));
		i = -1;
		while (len - 1 > i++)
			w[i] = s[len - len + i];
		w[i] = '\0';
		ft_lstaddend(&p_list, ft_lstnew(w, ft_strlen(w)));
		s = s + len;
	}
	return (p_list);
}
