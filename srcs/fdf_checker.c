/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:14:15 by alanter           #+#    #+#             */
/*   Updated: 2018/07/22 22:36:23 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	check_char(t_param *param)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < param->map_h)
	{
		while ((size_t)j < ft_strlen(param->map[i]))
		{
			if (param->map[i][j] != ' ' && !(ft_isdigit(param->map[i][j])))
			{
				ft_printf("voilà mon erreur : %d, à cet index [%d][%d]\n", param->map[i][j], j, i);
				return (-1);
			}
			while (ft_isdigit(param->map[i][j]))
				j++;
			while (param->map[i][j] == ' ')
				j++;
		}
		j = 0;
		i++;
	}
	return (0);
}


/*
** Check for errors while initiating parameters in init_param.
*/

int	fdf_checker(t_mlx *mlx)
{
	if (mlx->param.error == 1)
		ft_printf("Error: No data found.\n");
	else if (mlx->param.error == 2)
		ft_printf("Error: Found wrong line length. Exiting.\n");
	else if (mlx->param.error == 3)
		ft_printf("Error: Map is too big. Size max is 4096 x 4096.\n");
	//else if (check_char(&mlx->param) < 0)
	//	ft_printf("Error: Data corrupted - must only contain spaces and numbers.\n");
	else
		return (0);
	return (-1);
	//	Usage : ./fdf <filename> [ case_size z_size ]
}
