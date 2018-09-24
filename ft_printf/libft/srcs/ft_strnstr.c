/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:38:22 by alanter           #+#    #+#             */
/*   Updated: 2017/12/03 21:35:42 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	int		length;

	h = (char *)haystack;
	n = (char *)needle;
	length = ft_strlen(needle);
	if (h[0])
		;
	if (length == 0 || h == n)
		return (h);
	while (len && (int)len >= length && *h != 0)
	{
		if (ft_strncmp(h, n, length) == 0)
			return (h);
		h++;
		len--;
	}
	return (NULL);
}
