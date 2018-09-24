/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:20:18 by alanter           #+#    #+#             */
/*   Updated: 2018/06/23 00:49:37 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		size_lltoa(long long n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static	char	*ft_lltoa_neg(char *ret, int i, long long n, int base)
{
	while (i != 0)
	{
		ret[i] = '0' - (n % base);
		n /= base;
		i--;
	}
	ret[0] = '-';
	return (ret);
}

char			*ft_lltoa_base(long long n, int base)
{
	char	*ret;
	int		i;

	i = size_lltoa(n, base) - 1;
	if (!(ret = (char*)malloc(sizeof(char) * size_lltoa(n, base) + 1)))
		return (NULL);
	ret[i + 1] = 0;
	if (n < 0)
		return (ft_lltoa_neg(ret, i, n, base));
	else
	{
		while (i != -1)
		{
			if ((n % base) < 10)
				ret[i] = '0' + (n % base);
			else
				ret[i] = 87 + (n % base);
			n /= base;
			i--;
		}
	}
	return (ret);
}
