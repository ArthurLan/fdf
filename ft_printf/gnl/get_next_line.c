/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:44:58 by alanter           #+#    #+#             */
/*   Updated: 2018/07/21 16:25:17 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		store_in_line(t_list *fd_lst, char **line, int j)
{
	int		i;
	char	*new_buff;

	i = 0;
	if (j == 0)
		return (0);
	while (i < j)
	{
		line[0][i] = (BUFFC)[i];
		i++;
	}
	if ((BUFFC)[j] != 0)
	{
		if (!(new_buff = ft_strdup(&(BUFFC)[i + 1])))
			return (-1);
		free(BUFF);
		(BUFF) = new_buff;
		return (1);
	}
	free(BUFF);
	(BUFF) = "";
	return (1);
}

int		reader(t_list *fd_lst)
{
	char	*tmp;
	char	*tmp2;
	int		ret_read;
	char	**clean;

	clean = &(BUFF);
	ret_read = 0;
	if (!(tmp2 = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	if (!(tmp = ft_strdup(BUFF)))
		return (-1);
	if ((ret_read = read(fd_lst->FD, tmp2, BUFF_SIZE)) < 0)
		return (-1);
	if (ret_read != 0)
	{
		if (!((BUFF) = ft_strjoin(tmp, tmp2)))
			return (-1);
		if (*clean)
		{
			ft_printf("illogisme2...\n");
			free(clean);
		}
	}
	free(tmp);
	free(tmp2);
	return (ret_read);
}

int		buff_manager(t_list *fd_lst, char **line)
{
	int	ret_read;
	int	j;

	j = 0;
	ret_read = 0;
	while (!(ft_strchr(BUFF, SPLITTER)))
	{
		ret_read = reader(fd_lst);
		if (ret_read == -1)
			return (-1);
		if (ret_read <= 0 || ret_read > BUFF_SIZE)
			break ;
		if ((BUFFC)[0] == 0)
			return (0);
	}
	while ((BUFFC)[j] != SPLITTER && (BUFFC)[j] != 0)
		j++;
	if (!(*line = ft_memalloc(j + 1)))
		return (-1);
	if (*(BUFFC) == SPLITTER)
	{
		ft_memmove(BUFF, BUFF + 1, ft_strlen(BUFF + 1) + 1);
		return (1);
	}
	return (store_in_line(fd_lst, line, j));
}

t_list	*fd_manager(int fd, t_list *fd_lst, t_list **start_lst)
{
	t_list	*lst;

	lst = fd_lst;
	while (lst->next != NULL && (int)lst->FD != fd)
		lst = lst->next;
	if ((int)lst->FD == fd)
		return (lst);
	else
	{
		ft_lstadd(&fd_lst, ft_lstnew("", 1));
		if (!fd_lst)
			return (NULL);
		fd_lst->FD = fd;
		*start_lst = fd_lst;
		return (fd_lst);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*fd_lst;
	t_list			*start_lst;
	int				ret;

	if (line == NULL)
		return (-1);
	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	if (fd_lst == NULL)
	{
		if (!(fd_lst = ft_lstnew("", 1)))
			return (-1);
		fd_lst->FD = 0;
	}
	start_lst = fd_lst;
	if (!(fd_lst = fd_manager(fd, fd_lst, &start_lst)))
		return (-1);
	ret = buff_manager(fd_lst, line);
	if (ret == 0)
		free(*line);
	fd_lst = start_lst;
	return (ret);
}
