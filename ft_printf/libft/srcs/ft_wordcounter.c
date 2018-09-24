/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:28:30 by alanter           #+#    #+#             */
/*   Updated: 2018/07/24 22:38:35 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcounter(char *str, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (ft_strlen(str) != 0)
	{
		if (str[0] != c)
		{
			count++;
			i++;
		}
		if (str[0] != c)
			i++;
		while (str[i] != 0)
		{
			if (str[i] != c && str[i - 1] == c)
				count++;
			i++;
		}
	}
	return (count);
}
