/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:35:33 by alanter           #+#    #+#             */
/*   Updated: 2018/07/19 16:17:19 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void    ft_swap_coor(t_line *line)
{
	int    tmp;

	if (line->x1 < line->x2)
	{
		tmp = line->x1;
		line->x1 = line->x2;
		line->x2 = tmp;
		tmp = line->y1;
		line->y1 = line->y2;
		line->y2 = tmp;
	}
}

static void    ft_draw_pixel(t_mlx *mlx)
{
	if (BOOT(draw_hud) || (LINE(x1) >= (WIN_W / 9 + 1)
				&& LINE(x1) <= (WIN_W - 2)
				&& LINE(y1) >= 2 && LINE(y1) <= WIN_H - 47))
		IMG(data)[LINE(y1) * WIN_W + LINE(x1)] = LINE(color);
}

void        ft_draw_line(t_mlx *mlx)
{
	int ex;
	int ey;
	int err;
	int e;

	ft_swap_coor(&IMG(line));
	ex = abs(LINE(x2) - LINE(x1));
	ey = abs(LINE(y2) - LINE(y1));
	err = (ex > ey ? ex : -ey) / 2;
	while (LINE(x1) != LINE(x2) || LINE(y1) != LINE(y2))
	{
		e = err;
		ft_draw_pixel(mlx);

		if (e > -ex)
		{
			LINE(x1)--;
			err -= ey;
		}
		if (e < ey)
		{
			LINE(y1) > LINE(y2) ? LINE(y1)-- : LINE(y1)++;
			err += ex;
		}
	}
	ft_draw_pixel(mlx);
}
