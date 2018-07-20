/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:06:38 by alanter           #+#    #+#             */
/*   Updated: 2017/11/29 17:50:22 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			i;

	i = 0;
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (n != 0 || dst != src)
		while (n)
		{
			i++;
			if ((unsigned char)*csrc == (unsigned char)c)
			{
				*cdst++ = *csrc++;
				return ((unsigned char *)dst + i);
			}
			*cdst++ = *csrc++;
			n--;
		}
	return (NULL);
}
