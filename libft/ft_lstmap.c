/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:47:11 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 11:47:12 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*start_list;

	if (!lst || !f)
		return (NULL);
	start_list = f(lst);
	new_list = start_list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new_list->next = f(lst)))
			return (NULL);
		new_list = new_list->next;
	}
	return (start_list);
}
