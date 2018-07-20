/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultim_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:26:32 by alanter           #+#    #+#             */
/*   Updated: 2018/07/10 18:14:46 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Deux pointeurs sur strings
** deux int : nombre de caractères à copier depuis leur string respectives.
** if 0, nombre de caractères présents avant le premier \0.
**
** Alloue l'espace nécessaire à la string retournée en utilisant malloc.
**
** Attention la fonction accepte qu'une string null soit passée en paramètre
** renvoie une string si l'autre string n'est pas nulle.
**
** Ne libère pas la mémoire d'un pointeur nul
** --> éviter une double libération.
**
** si n1 et/ou n2 sont supérieur à 0, str renvoyée conserve le \0
*/

static char		*ft_strnjoin(char const *s1, char const *s2, int n1, int n2)
{
	char	*d;
	int		i;

	i = 0;
	if (!(d = (char *)ft_memalloc(n1 + n2 + 1)))
		return (NULL);
	while (n1--)
		d[i++] = *s1++;
	while (n2--)
		d[i++] = *s2++;
	return (d);
}

static char		*ft_sort_null(char *s1, char *s2, int n1, int n2)
{
	char *str;

	n1 = (n1 == 0) ? ft_strlen(s1) : n1;
	n2 = (n2 == 0) ? ft_strlen(s2) : n2;
	if ((s1 && s2) || n1 || n2)
		str = ft_strnjoin(s1, s2, n1, n2);
	else if (s1 && s2 == NULL)
		str = ft_strndup(s1, n1);
	else if (s1 == NULL && s2)
		str = ft_strndup(s2, n2);
	else
		str = NULL;
	return (str);
}

char			*ft_ultim_join(char **s1, char **s2, int n1, int n2)
{
	char *str;

	str = ft_sort_null(*s1, *s2, n1, n2);
	if (*s1 != NULL)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (*s2 != NULL)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (str);
}
