/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 18:59:59 by alanter           #+#    #+#             */
/*   Updated: 2018/06/21 19:12:38 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoll(const char *str)
{
	long long int	ret;
	int				i;
	int				neg;

	ret = 0;
	i = 0;
	neg = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		ret = ret * 10 + ((long long int)str[i++] - '0');
	if (i > 19 || ret > 9223372036854775807)
		return ((neg == 1) ? -1 : 0);
	return (ret * (long long int)neg);
}
