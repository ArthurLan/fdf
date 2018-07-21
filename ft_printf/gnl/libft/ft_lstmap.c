/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:31:40 by alanter           #+#    #+#             */
/*   Updated: 2017/12/03 18:33:57 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmpmap;
	t_list	*lstmap;
	t_list	*tmplst;

	if (!(lst == NULL))
	{
		if (!(lstmap = f(ft_lstnew(lst->content, lst->content_size))))
			return (NULL);
		tmpmap = lstmap;
		tmplst = lst;
		tmplst = tmplst->next;
		while (tmplst != NULL)
		{
			if (!(tmpmap->next =
						f(ft_lstnew(tmplst->content, tmplst->content_size))))
				return (NULL);
			tmpmap = tmpmap->next;
			tmplst = tmplst->next;
		}
		return (lstmap);
	}
	return (NULL);
}
