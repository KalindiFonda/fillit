/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:46:02 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/25 09:46:06 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstaddend(t_list **begin_list, t_list *new)
{
	t_list *current;

	current = *begin_list;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
		*begin_list = new;
}
