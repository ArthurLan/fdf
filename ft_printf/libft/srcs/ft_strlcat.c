/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:49:57 by alanter           #+#    #+#             */
/*   Updated: 2017/12/03 14:48:49 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		dlen;

	d = dst;
	s = src;
	while (size-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	size = size + 1;
	if (size == 0)
		return (dlen + ft_strlen(s));
	while (*s != 0 && size != 1)
	{
		if (size-- != 0)
			*d++ = *s;
		s++;
	}
	*d = 0;
	return (dlen + ft_strlen(src));
}
