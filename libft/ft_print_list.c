/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:52:45 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 14:52:48 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_print_list(t_list *list)
{
	while (list)
	{
		ft_putstr((char*)list->content);
		ft_putchar(',');
		list = list->next;
	}
	ft_putchar('\n');
}
