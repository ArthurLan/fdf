/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:21:56 by alanter           #+#    #+#             */
/*   Updated: 2017/12/03 14:52:17 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*d;

	d = (char *)s;
	i = ft_strlen(s);
	if (c == 0)
		return (&d[i]);
	while (i != -1)
	{
		if (d[i] == c)
			return (&d[i]);
		i--;
	}
	return (NULL);
}
