/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:17:26 by alanter           #+#    #+#             */
/*   Updated: 2018/06/23 00:56:51 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ATTENTION : ONLY USE WITH ALLOCATED CHAR* WITH MALLOC
** Vérifier fonctionnement (fin printf)
*/

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*d;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(d = (char *)malloc(sizeof(char)
					* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i++] != 0)
		d[i] = s1[i];
	while (s2[j] != 0)
		d[i++] = s2[j++];
	d[i] = 0;
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	return (d);
}
