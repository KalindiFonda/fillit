/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:47:02 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 11:47:03 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;

	current = *alst;
	if (current && del)
	{
		(*del)(current->content, current->content_size);
		free(*alst);
		*alst = NULL;
	}
}
