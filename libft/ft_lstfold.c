/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:47:23 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 11:47:26 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_lstfold(t_list *lst, void *(*f)(void *, void *))
{
	t_list	*current;
	void	*result;

	if (!lst)
		return (0);
	current = lst;
	result = lst->content;
	current = current->next;
	while (current->content)
	{
		result = f(result, current->content);
		current = current->next;
	}
	return (result);
}
