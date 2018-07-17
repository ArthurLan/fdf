/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:38:41 by alanter           #+#    #+#             */
/*   Updated: 2018/07/17 20:27:08 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	fill_pixel(unsigned int *img, int x, int y, int color)
{
	img[y * WIN_WIDTH + x] = color;
}

/*
	isox = x - y;
	isoy = (x + y) / 2;
	fill_pixel(img, isox, isoy, 0xFFFFFF);
	*/

void	draw_point(unsigned int *img, const t_param *param, int x, int y)
{
	int yb;
	int isox;
	int isoy;

	yb = y;
	while (--x >= 0)
	{
		while (--y >= 0)
		{
			isox = (int)round((x - y ) * param->scale + param->offset_x );
			isoy = (int)round(((x + y) / 2.) * param->scale + param->offset_y);
			//fill_pixel(img, x * scale + origin, y * scale + origin, 0xFFFFFF);
			fill_pixel(img, isox, isoy, 0xFFFFFF);
		}
		y = yb;
	}
}
