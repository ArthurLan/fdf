/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:53:43 by alanter           #+#    #+#             */
/*   Updated: 2018/07/10 17:38:49 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Permet d'échanger deux charactères au sein d'une string
** ou entre deux string en envoyant leurs adresses respectives
*/

void	ft_switchar(char *c1, char *c2)
{
	char tmp;

	tmp = 0;
	if (c1 && c2)
	{
		tmp = *c2;
		*c2 = *c1;
		*c1 = tmp;
	}
}
