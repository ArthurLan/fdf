/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:21:26 by alanter           #+#    #+#             */
/*   Updated: 2018/07/23 20:19:17 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



static void	coef(int key, t_mlx *mlx)
{
	if (key == 69)
		mlx->param.coef += 5;
	else if (key == 78)
		mlx->param.coef -= 5;
}

static void	less(int key, t_mlx *mlx)
{
	if (key == 27 && mlx->param.less > 0)
		mlx->param.less--;
	else if (key == 24)
		mlx->param.less++;
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
}

static void	zoom(int key, t_mlx *mlx)
{
	if (key == 34)// && mlx->param.scale < 16)
		mlx->param.scale += mlx->param.zoom;
	else if (key == 31 && mlx->param.scale > 2)
		mlx->param.scale -= mlx->param.zoom;
}

int	fdf_bonus(int key, t_mlx *mlx, int fd, char *argv)
{
	if (key == 53)
		exit(0);
	else if (key == 69 || key == 78)
		coef(key, mlx);
	else if (key == 27 || key == 24)
		less(key, mlx);
	else if (key == 8)
		mlx->param.compressor = (mlx->param.compressor == 1) ? 0 : 1;
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		move(key, mlx);
	else if (key == 34 || key == 31)
	{
		zoom(key, mlx);
		if (key == 34)
			system("say zooming in");
		if (key == 31)
			system("say zooming out");
	}
	else if (key == 15)
		init_param(mlx, fd, argv);
	else
	{
		ft_printf("Voilà ma touche : %d\n", key);
		return (0);
	}
	return (1);
}
