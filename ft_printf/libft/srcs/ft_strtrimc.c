/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:59:37 by alanter           #+#    #+#             */
/*   Updated: 2017/12/03 19:03:53 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	char	*ret;
	int		i;
	int		j;
	int		size;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == c)
		i++;
	if (s[i] == 0)
		return ((char*)&s[i]);
	while (s[j] == c)
		j--;
	size = j - i + 1;
	if (!(ret = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	j = 0;
	while (j < size)
		ret[j++] = s[i++];
	ret[j] = 0;
	return (ret);
}
