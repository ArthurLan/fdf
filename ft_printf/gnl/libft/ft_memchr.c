/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:30:52 by alanter           #+#    #+#             */
/*   Updated: 2017/12/03 20:33:10 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*chrs;

	chrs = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)chrs[i] == (unsigned char)c)
			return (&chrs[i]);
		i++;
	}
	return (NULL);
}
