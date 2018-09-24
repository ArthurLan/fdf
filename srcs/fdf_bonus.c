/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:21:26 by alanter           #+#    #+#             */
/*   Updated: 2018/07/24 21:02:36 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	coef(int key, t_mlx *mlx)
{
	if (key == 69)
		mlx->param.coef += 5;
	else if (key == 78)
		mlx->param.coef -= 5;
	mlx->param.voice = (mlx->param.voice != -3) ? 69 : -3;
}

static void	less(int key, t_mlx *mlx)
{
	if (key == 27 && mlx->param.less > 0)
		mlx->param.less--;
	else if (key == 24)
		mlx->param.less++;
	mlx->param.voice = (mlx->param.voice != -5) ? 24 : -5;
}

static void	move(int key, t_mlx *mlx)
{
	if (key == 123)
		mlx->param.movex--;
	else if (key == 124)
		mlx->param.movex++;
	else if (key == 125)
		mlx->param.movey++;
	else if (key == 126)
		mlx->param.movey--;
	mlx->param.voice = (mlx->param.voice != -2) ? 122 : -2;
}

static void	colo(int key, t_mlx *mlx)
{
	if (key == 83)
	{
		mlx->param.voice = 83;
		mlx->param.coloredge = 0;
	}
	else if (key == 84)
	{
		mlx->param.voice = 84;
		mlx->param.coloredge = 1;
	}
	else if (key == 85)
	{
		mlx->param.voice = 85;
		mlx->param.coloredge = 2;
	}
}

int			fdf_bonus(int key, t_mlx *mlx, int fd, char *argv)
{
	if (key == 53)
		exit(0);
	else if (key == 69 || key == 78)
		coef(key, mlx);
	else if (key == 27 || key == 24)
		less(key, mlx);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		move(key, mlx);
	else if (key == 83 || key == 84 || key == 85)
		colo(key, mlx);
	else if (key == 8 && (mlx->param.voice = 8))
		mlx->param.compressor = (mlx->param.compressor == 1) ? 0 : 1;
	else if (key == 15 || key == 34 || key == 31)
	{
		if (!(fdf_bonusb(key, mlx, fd, argv)))
			return (0);
	}
	else if (key == 9 && (mlx->param.voice = 1))
		mlx->param.voice_active = (mlx->param.voice_active == 0) ? 1 : 0;
	else
		return (0);
	if (mlx->param.voice_active)
		fdf_voice(mlx);
	return (1);
}
