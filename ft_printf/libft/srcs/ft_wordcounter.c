/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:28:30 by alanter           #+#    #+#             */
/*   Updated: 2018/07/21 20:10:17 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t     ft_wordcounter(char *s2, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (ft_strlen(s2) != 0)
	{
		if (s2[0] != c)
		{
			count++;
			i++;
		}
		while (s2[i] != 0)
		{
			if (s2[i - 1] == c && s2[i] != c)
				count++;
			i++;
		}
	}
	return (count);
}
