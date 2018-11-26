/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:52:31 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 10:52:32 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa(int n)
{
	int		len;
	char	*nums;

	len = ft_int_len(n);
	if (!(nums = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nums[len--] = '\0';
	if (n == -2147483648)
	{
		nums[len--] = '8';
		n = -214748364;
	}
	if (n < 0)
	{
		nums[0] = '-';
		n *= -1;
	}
	while (n / 10)
	{
		nums[len--] = (n % 10) + '0';
		n = n / 10;
	}
	nums[len] = (n % 10) + '0';
	return (nums);
}
