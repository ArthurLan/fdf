/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:22:07 by alanter           #+#    #+#             */
/*   Updated: 2018/07/16 16:42:47 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (src)
	{
		if (!(dest = (char *)malloc(sizeof(*src) * ft_strlen(src) + 1)))
			return (NULL);
		while (src[i] != 0)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
		return (dest);
	}
	else
		return (NULL);
}
