/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:47:04 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 11:47:06 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*next;

	if (!alst)
		return ;
	current = *alst;
	while (current && del)
	{
		next = current->next;
		(*del)(current->content, current->content_size);
		free(*alst);
		*alst = NULL;
		if (next)
		{
			*current = *next;
			*alst = next;
		}
		else
			return ;
	}
}
