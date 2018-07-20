/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:14:15 by alanter           #+#    #+#             */
/*   Updated: 2018/07/20 16:56:30 by alanter          ###   ########.fr       */
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
		while (j < param->map_l)
		{
			if (param->map[i][j] != ' ' && !(ft_isdigit(param->map[i][j])))
				return (-1);
			while(ft_isdigit(param->map[i][j]))
				j++;
			while(!(ft_isdigit(param->map[i][j])))
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
		ft_printf("No data found.\n");
	else if (mlx->param.error == 2)
		ft_printf("Found wrong line length. Exiting.\n");
	else if (check_char(&mlx->param) < 0)
		ft_printf("Data corrupted : must only contain spaces and numbers\n");
	else
		return (0);
	return (-1);
	//	Usage : ./fdf <filename> [ case_size z_size ]
}
