/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:52:03 by alanter           #+#    #+#             */
/*   Updated: 2017/11/29 18:16:08 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(d = (char*)malloc(len + 1)))
		return (NULL);
	while (i < len)
		d[i++] = s[start++];
	d[i] = 0;
	return (d);
}
