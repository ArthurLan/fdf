/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:01:42 by alanter           #+#    #+#             */
/*   Updated: 2018/07/19 20:04:09 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel(unsigned int *img, int x, int y, int color)
{
	img[y * WIN_WIDTH + x] = color;
}

void        ft_draw_line(unsigned int *img, t_coord a, t_coord b)//, int *i)
{

/*
	ft_printf("Je m'apprete à imprimer les %d lignes\n", *i);
	*i += 1;
	if (a.isox)
		;
	if (b.isox)
		;
*/
	if (img)
		;
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
		//ft_draw_pixel(mlx);

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
	//ft_draw_pixel(mlx);
}


void	iso_point(const t_param *p, int x, int y)
{
	int yb;
	//int isox;
	//int isoy;
	int	height_val;

	height_val = 0;
	yb = y;
	ft_printf("x = %d, y = %d\n", x, y); 
	while (--x >= 0)
	{
		while (--y >= 0)
		{
			height_val = p->coord[y][x].z;
			//ft_printf("coord[%d][%d].z = [%d] ; et height_val : %d\n", y, x, p->coord[y ][x].z, height_val);
			//ft_printf("height_val : %d\n", height_val);
			p->coord[y][x].isox = (int)round((x - y) * p->scale + p->offset_x );
			p->coord[y][x].isoy = (int)round(((x + y) / 2.) * p->scale + p->offset_y) - height_val / 1.3;
			//fill_pixel(img, p->coord[y][x].isox, p->coord[y][x].isoy, 0xFF0000);
		}
		y = yb;
	}
}

void	fdf_draw(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	iso_point(&mlx->param, mlx->param.map_l, mlx->param.map_h);
	while (x < mlx->param.map_l)
	{
		while (y < mlx->param.map_h - 1)
		{
			ft_draw_line(mlx->img.img, mlx->param.coord[y][x], mlx->param.coord[y + 1][x]);
			y++;
		}
		x++;
		y = 0;
	}
	x = 1;
	while (x < mlx->param.map_l)
	{
		while (y < mlx->param.map_h)
		{
			ft_draw_line(mlx->img.img, mlx->param.coord[y][x], mlx->param.coord[y][x - 1]);
			y++;
		}
		x++;
		y = 0;
	}
}
