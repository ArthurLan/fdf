/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:01:42 by alanter           #+#    #+#             */
/*   Updated: 2018/07/20 14:04:33 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel(unsigned int *img, int x, int y, int color)
{
	//protéger l'écriture en dehors de la fenetre
	img[y * WIN_WIDTH + x] = color;
}

void        ft_draw_line(unsigned int *img, t_coord a, t_coord b)//, int *i)
{
	int ex;
	int ey;
	int err;
	int e;

	//ft_swap_coor(&IMG(line));
	ex = abs(b.isox - a.isox);
	ey = abs(b.isoy - a.isoy);
	err = (ex > ey ? ex : -ey) / 2;
	while (a.isox != b.isox || a.isoy != b.isoy)
	{
		e = err;
		fill_pixel(img, a.isox, a.isoy, 0xFFFFFF);
		if (e > -ex)
		{
			a.isox--;
			err -= ey;
		}
		if (e < ey)
		{
			a.isoy > b.isoy ? a.isoy-- : a.isoy++;
			err += ex;
		}
	}
	fill_pixel(img, a.isox, a.isoy, 0xFFFFFF);
}

void	iso_point(const t_param *p, int x, int y)
{
	int yb;
	int	z;

	z = 0;
	yb = y;
	ft_printf("x = %d, y = %d\n", x, y); 
	while (--x >= 0)
	{
		while (--y >= 0)
		{
			z = p->coord[y][x].z;
			p->coord[y][x].isox = (int)round((x - y) * p->scale + p->offset_x);
			p->coord[y][x].isoy = (int)round(((x + y) / 2.) * p->scale + p->offset_y) - z * 3;// / p->coef;
		}
		y = yb;
	}
}

void	fdf_draw(t_mlx *mlx)
{
	int x;
	int y;

	x = -1;
	y = -1;
	iso_point(&mlx->param, mlx->param.map_l, mlx->param.map_h);
	while (++x < mlx->param.map_l)
	{
		while (++y < mlx->param.map_h - 1)
			ft_draw_line(mlx->img.img, mlx->param.coord[y][x], mlx->param.coord[y + 1][x]);
		y = -1;
	}
	x = 0;
	while (++x < mlx->param.map_l)
	{
		while (++y < mlx->param.map_h)
			ft_draw_line(mlx->img.img, mlx->param.coord[y][x], mlx->param.coord[y][x - 1]);
		y = -1;
	}
}
