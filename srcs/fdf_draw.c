/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:38:41 by alanter           #+#    #+#             */
/*   Updated: 2018/07/18 19:33:20 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel(unsigned int *img, int x, int y, int color)
{
	img[y * WIN_WIDTH + x] = color;
}

void	draw_point(unsigned int *img, const t_param *param, int x, int y)
{
	int yb;
	int isox;
	int isoy;
	int	height_val;

	height_val = 0;
	yb = y;
	ft_printf("x = %d, y = %d\n", x, y); 
	while (--x >= 0)
	{
		while (--y >= 0)
		{
			//if (height_val)
			//	;
			height_val = param->map_val[y][x];
			//ft_printf("map_val[%d][%d] = [%d] ; et height_val : %d\n", y, x, param->map_val[y ][x], height_val);
			//ft_printf("height_val : %d\n", height_val);
			isox = (int)round((x - y) * param->scale + param->offset_x );
			isoy = (int)round(((x + y) / 2.) * param->scale + param->offset_y) - height_val;
			fill_pixel(img, isox, isoy, 0xFFFFFF);
		}
		y = yb;
	}
}
