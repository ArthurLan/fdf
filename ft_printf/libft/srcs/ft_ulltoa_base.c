/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:20:18 by alanter           #+#    #+#             */
/*   Updated: 2018/07/10 17:40:30 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		size_ulltoa(unsigned long long n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char			*ft_ulltoa_base(unsigned long long n, int base)
{
	char	*ret;
	int		i;

	i = size_ulltoa(n, base) - 1;
	if (!(ret = (char*)malloc(sizeof(char) * size_ulltoa(n, base) + 1)))
		return (NULL);
	ret[i + 1] = 0;
	while (i != -1)
	{
		if ((n % base) < 10)
			ret[i] = '0' + (n % base);
		else
			ret[i] = 87 + (n % base);
		n /= base;
		i--;
	}
	return (ret);
}
