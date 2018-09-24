/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:01:42 by alanter           #+#    #+#             */
/*   Updated: 2018/07/24 23:38:31 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fill_pixel(unsigned int *img, int x, int y, int z)
{
	if (x < WIN_WIDTH && y < WIN_HEIGHT && x >= 0 && y >= 0)
	{
		if (z < 0)
			img[y * WIN_WIDTH + x] = 0x01013c;
		else if (z == 0)
			img[y * WIN_WIDTH + x] = 0xffffff;
		else if (z <= 10)
			img[y * WIN_WIDTH + x] = 0xffffdd;
		else if (z <= 10)
			img[y * WIN_WIDTH + x] = 0xffff51;
		else if (z <= 25)
			img[y * WIN_WIDTH + x] = 0xffff15;
		else if (z <= 50)
			img[y * WIN_WIDTH + x] = 0xff7d23;
		else if (z <= 100)
			img[y * WIN_WIDTH + x] = 0xff0051;
		else
			img[y * WIN_WIDTH + x] = 0xff140d;
	}
}

static void		ft_draw_line(unsigned int *img, t_coord a, t_coord b, t_param p)
{
	int ex;
	int ey;
	int err;
	int e;

	ex = abs(b.isox - a.isox);
	ey = abs(b.isoy - a.isoy);
	err = (ex > ey ? ex : -ey) / 2;
	while (a.isox != b.isox || a.isoy != b.isoy)
	{
		e = err;
		if (p.coloredge == 1)
			a.color = (a.color < b.color) ? a.color : b.color;
		else if (p.coloredge == 2)
			a.color = (a.color > b.color) ? a.color : b.color;
		else
			a.color = 0;
		fill_pixel(img, a.isox, a.isoy, a.color);
		if (e > -ex && (err -= ey) != 1e-9)
			a.isox--;
		if (e < ey && (err += ex) != 1e-9)
			a.isoy > b.isoy ? a.isoy-- : a.isoy++;
	}
	fill_pixel(img, a.isox, a.isoy, 0xFFFFFF);
}

static void		ft_compressor(int *z)
{
	if (*z > 50)
		*z = 50 + (*z - 50) / 10;
	if (*z > 100)
		*z = 100 + (*z - 100) / 20;
	if (*z > 200)
		*z = 200 + (*z - 200) / 30;
}

void			iso_point(const t_param *p, int x, int y)
{
	int yb;
	int	z;

	z = 0;
	yb = y;
	while (--x >= 0)
	{
		while (--y >= 0)
		{
			z = (p->coord[y][x].z > 0) ? p->coord[y][x].z + p->coef
				: p->coord[y][x].z - p->coef;
			z = (p->coord[y][x].z == 0) ? p->coord[y][x].z : z;
			p->coord[y][x].color = z;
			if (p->compressor)
				ft_compressor(&z);
			p->coord[y][x].isox = (int)round((x - y) * p->scale
					+ p->offset_x);
			p->coord[y][x].isoy = (int)round(((x + y) / 2.) * p->scale
					+ p->offset_y) - z;
			p->coord[y][x].isox += p->movex * 10;
			p->coord[y][x].isoy += p->movey * 10;
		}
		y = yb;
	}
}

void			fdf_draw(t_mlx *mlx, int x, int y)
{
	iso_point(&mlx->param, mlx->param.map_l, mlx->param.map_h);
	while (++x < mlx->param.map_l)
	{
		while (++y < mlx->param.map_h - 1)
		{
			if (mlx->param.less <= 1 || y % mlx->param.less == 0)
				ft_draw_line(mlx->img.img, mlx->param.coord[y][x],
						mlx->param.coord[y + 1][x], mlx->param);
		}
		y = -1;
	}
	x = 0;
	while (++x < mlx->param.map_l)
	{
		while (++y < mlx->param.map_h)
		{
			if (mlx->param.less <= 1 || x % mlx->param.less == 0)
				ft_draw_line(mlx->img.img, mlx->param.coord[y][x],
						mlx->param.coord[y][x - 1], mlx->param);
		}
		y = -1;
	}
}
