/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:23:50 by alanter           #+#    #+#             */
/*   Updated: 2017/11/29 21:31:46 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*word(char *s2, int c)
{
	char	*word;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (s2[size] != c && s2[size] != 0)
		size++;
	if (!(word = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		word[i] = s2[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static	int		wordcounter(char *s2, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (ft_strlen(s2) != 0)
	{
		if (s2[0] != c)
		{
			count++;
			i++;
		}
		while (s2[i] != 0)
		{
			if (s2[i - 1] == c && s2[i] != c)
				count++;
			i++;
		}
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	char	*s2;
	int		i;
	int		count;

	i = 0;
	if (s == NULL)
		return (NULL);
	s2 = (char *)s;
	count = wordcounter(s2, c);
	if (!(dst = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (i < count)
	{
		while (*s2 == c)
			s2++;
		dst[i] = word(s2, c);
		while (*s2 != c && *s2 != 0)
			s2++;
		i++;
	}
	dst[i] = 0;
	return (dst);
}
