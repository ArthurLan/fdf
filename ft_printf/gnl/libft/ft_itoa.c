/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 23:47:56 by alanter           #+#    #+#             */
/*   Updated: 2017/11/29 21:35:47 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		size_itoa(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	char	*ft_itoa_neg(char *ret, int i, int n)
{
	while (i != 0)
	{
		ret[i] = '0' - (n % 10);
		n /= 10;
		i--;
	}
	ret[0] = '-';
	return (ret);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		i;

	i = size_itoa(n) - 1;
	if (!(ret = (char*)malloc(sizeof(char) * size_itoa(n) + 1)))
		return (NULL);
	ret[i + 1] = 0;
	if (n < 0)
		return (ft_itoa_neg(ret, i, n));
	else
	{
		while (i != -1)
		{
			ret[i] = '0' + (n % 10);
			n /= 10;
			i--;
		}
	}
	return (ret);
}
