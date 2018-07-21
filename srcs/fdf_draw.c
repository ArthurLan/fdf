/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:01:42 by alanter           #+#    #+#             */
/*   Updated: 2018/07/22 00:01:55 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_pixel(unsigned int *img, const int x, const int y, const int color)
{
	if (x < WIN_WIDTH && y < WIN_HEIGHT && x >= 0 && y >= 0)
		img[y * WIN_WIDTH + x] = color;
}

static void	ft_draw_line(unsigned int *img, t_coord a, t_coord b)//, int *i)
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
	//ft_printf("test 1\n");
		e = err;
		fill_pixel(img, a.isox, a.isoy, 0xFFFFFF);
		//fill_pixel(img, a.isox, a.isoy, round(0x00000F * a.z));
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

void	ft_compressor(int *z)
{
	if (*z > 40)
		*z = 40 + *z / 10;
	if (*z > 100)
		*z = 100 + *z / 100;
	if (*z > 1000)
		*z = 1000 + *z / 1000;
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
			ft_compressor(&z);
			p->coord[y][x].isox = (int)round((x - y) * p->scale + p->offset_x);
			p->coord[y][x].isoy = (int)round(((x + y) / 2.) * p->scale + p->offset_y) - z * 10 / p->coef;
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
		{
		//	if (y % 1 == 0)
				ft_draw_line(mlx->img.img, mlx->param.coord[y][x], mlx->param.coord[y + 1][x]);
		}
		y = -1;
	}
	x = 0;
	while (++x < mlx->param.map_l)
	{
		while (++y < mlx->param.map_h)
		{
	//		if (x % 1 == 0)
			ft_draw_line(mlx->img.img, mlx->param.coord[y][x], mlx->param.coord[y][x - 1]);
		}
		y = -1;
	}
}
