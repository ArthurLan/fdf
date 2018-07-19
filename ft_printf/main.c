/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:44:58 by alanter           #+#    #+#             */
/*   Updated: 2018/04/04 14:36:33 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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

	//ouvre et affiche la première ligne du premier fichier
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
	ret = get_next_line(fd, &line);
	ft_putnbr(ret);
	ft_putstr("\n");
	ret = get_next_line(fd, &line);
	ft_putnbr(ret);
	ft_putstr("\n");
/*	
	ft_putnbr(get_next_line(fd, line));
	ft_putstr(line[0]);
	ft_putstr("\n");

	//ouvre le 2ème fichier

	fd = open(argv[2], O_RDONLY);
	if (fd < 0)
		return (-1);
	
	//ouvre et affiche la première ligne du fichier 2
	
	ft_putnbr(get_next_line(fd, line));
	ft_putstr(line[0]);
	ft_putstr("\n");

	//ouvre et affiche la ligne 3 du premier fichier
	
	fd = 3;
	ft_putnbr(get_next_line(fd, line));
	ft_putstr(line[0]);
	ft_putstr("\n");
	
	//ouvre et affiche la ligne 2 du fichier 2
	
	fd = 4;
	ft_putnbr(get_next_line(fd, line));
	ft_putstr(line[0]);
	ft_putstr("\n");
	ft_putnbr(get_next_line(fd, line));
	ft_putstr(line[0]);
	ft_putstr("\n");
	ft_putnbr(get_next_line(fd, line));
	ft_putstr(line[0]);
	ft_putstr("\n");
	ft_putnbr(get_next_line(fd, line));
	ft_putstr(line[0]);
	ft_putstr("\n");
*/
	return (0);
}
