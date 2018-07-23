/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 23:11:54 by alanter           #+#    #+#             */
/*   Updated: 2018/07/21 18:36:04 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./ft_printf.h"
# include <fcntl.h>
# define BUFF_SIZE 32
# define SPLITTER '\n'
# define FD content_size
# define BUFFC (char*)fd_lst->content
# define BUFF fd_lst->content

int	get_next_line(const int fd, char **line);

#endif
