/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:55:48 by alanter           #+#    #+#             */
/*   Updated: 2018/07/24 23:58:15 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	reset(t_mlx *mlx, int fd, char *argv)
{
	mlx->param.coef = 0;
	mlx->param.compressor = 0;
	mlx->param.movex = 0;
	mlx->param.movey = 0;
	mlx->param.coloredge = 0;
	init_param(mlx, fd, argv);
	mlx->param.voice = (mlx->param.voice != -4) ? 15 : -4;
}

static void	zoom(int key, t_mlx *mlx)
{
	if (key == 34 && mlx->param.scale < 4096)
		mlx->param.scale += mlx->param.zoom;
	else if (key == 31 && mlx->param.scale > 2)
		mlx->param.scale -= mlx->param.zoom;
	mlx->param.voice = (mlx->param.voice != -1) ? 34 : -1;
}

int			fdf_bonusb(int key, t_mlx *mlx, int fd, char *argv)
{
	if (key == 15)
		reset(mlx, fd, argv);
	else if (key == 34 || key == 31)
		zoom(key, mlx);
	else
		return (0);
	return (1);
}
