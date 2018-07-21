/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:44:58 by alanter           #+#    #+#             */
/*   Updated: 2018/07/21 18:46:12 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			fd;
	char		*line;
	int			ret;

	fd = 0;

	if (argc)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (-1);
	}

	line = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		ft_putnbr(ret);
		ft_putstr("\n");
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
		line = NULL;
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd,&line);
//	if (line)
//		free(line);
	return (0);
}
