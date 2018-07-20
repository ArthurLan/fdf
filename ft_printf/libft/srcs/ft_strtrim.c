/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:36:15 by alanter           #+#    #+#             */
/*   Updated: 2017/12/03 21:30:20 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;
	int		j;
	int		size;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == 0)
		return (ft_strnew(0));
	while (s[j] == 32 || s[j] == '\n' || s[j] == '\t')
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
