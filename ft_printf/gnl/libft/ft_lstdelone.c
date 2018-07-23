/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 23:43:48 by alanter           #+#    #+#             */
/*   Updated: 2017/12/01 15:54:32 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lstdelone;
	t_list	*nexttmp;

	lstdelone = *alst;
	nexttmp = lstdelone->next;
	del(lstdelone->content, lstdelone->content_size);
	free(lstdelone);
	*alst = NULL;
}
