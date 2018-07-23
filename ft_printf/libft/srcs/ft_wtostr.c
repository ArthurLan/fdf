/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:01:42 by alanter           #+#    #+#             */
/*   Updated: 2018/06/23 01:02:03 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	storew(wchar_t *wstr, char *str, size_t size, int i)
{
	while (size--)
	{
		if (*wstr <= 0x7F)
			str[i++] = *wstr;
		else if (size-- && *wstr <= 0x7FF)
		{
			str[i++] = ((*wstr >> 6) | 0xC0);
			str[i++] = ((*wstr & 0x3F) | 0x80);
		}
		else if (size-- && *wstr <= 0xFFFF)
		{
			str[i++] = ((*wstr >> 12) | 0xE0);
			str[i++] = (((*wstr >> 6) & 0x3F) | 0x80);
			str[i++] = ((*wstr & 0x3F) | 0x80);
		}
		else if (size-- && *wstr <= 0x10FFFF)
		{
			str[i++] = ((*wstr >> 18) | 0xF0);
			str[i++] = (((*wstr >> 12) & 0x3F) | 0x80);
			str[i++] = (((*wstr >> 6) & 0x3F) | 0x80);
			str[i++] = ((*wstr & 0x3F) | 0x80);
		}
		wstr++;
	}
}

char	*ft_wtostr(wchar_t *wstr)
{
	size_t	size;
	char	*str;
	int		i;

	i = 0;
	size = ft_strwlen(wstr);
	str = NULL;
	if (wstr)
	{
		str = (char *)ft_memalloc(size + 1);
		storew(wstr, str, size, i);
	}
	return (str);
}
