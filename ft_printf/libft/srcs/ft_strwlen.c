/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:36:34 by alanter           #+#    #+#             */
/*   Updated: 2018/06/22 20:44:51 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strwlen(wchar_t *str)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	if (str != NULL)
	{
		while (str[i] != 0)
		{
			len += ft_charwlen(str[i]);
			i++;
		}
	}
	return (len);
}
