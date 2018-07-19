/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:28:30 by alanter           #+#    #+#             */
/*   Updated: 2018/07/19 16:31:00 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_wordcounter(char *s2, char c)
{
	int i;
	int count;

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
