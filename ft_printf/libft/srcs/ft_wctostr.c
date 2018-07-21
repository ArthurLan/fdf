/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 19:09:47 by alanter           #+#    #+#             */
/*   Updated: 2018/07/12 16:10:31 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	storewc(wint_t wc, char *str, int i)
{
	if (wc <= 0x7F)
		str[i++] = wc;
	else if (wc <= 0x7FF)
	{
		str[i++] = ((wc >> 6) | 0xC0);
		str[i++] = ((wc & 0x3F) | 0x80);
	}
	else if (wc <= 0xFFFF)
	{
		str[i++] = ((wc >> 12) | 0xE0);
		str[i++] = (((wc >> 6) & 0x3F) | 0x80);
		str[i++] = ((wc & 0x3F) | 0x80);
	}
	else if (wc <= 0x10FFFF)
	{
		str[i++] = ((wc >> 18) | 0xF0);
		str[i++] = (((wc >> 12) & 0x3F) | 0x80);
		str[i++] = (((wc >> 6) & 0x3F) | 0x80);
		str[i++] = ((wc & 0x3F) | 0x80);
	}
}

char	*ft_wctostr(wint_t wc)
{
	size_t	size;
	char	*str;
	int		i;

	i = 0;
	size = ft_charwlen(wc);
	str = NULL;
	if (wc >= 0)
	{
		str = (char *)ft_memalloc(size + 1);
		storewc(wc, str, i);
	}
	return (str);
}
