/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrcounter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 22:37:50 by alanter           #+#    #+#             */
/*   Updated: 2018/07/25 00:18:53 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrcounter(char *str, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (ft_strlen(str) != 0)
	{
		if (str[0] != c && (ft_isdigit(str[i]) || str[0] == '-'))
		{
			count++;
			i++;
		}
		if (str[0] != c)
			i++;
		while (str[i] != 0)
		{
			if (str[i] != c && str[i - 1] == c
					&& (ft_isdigit(str[i]) || str[i] == '-'))
				count++;
			i++;
		}
	}
	return (count);
}
