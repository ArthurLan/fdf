/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:05:08 by alanter           #+#    #+#             */
/*   Updated: 2018/07/17 00:21:17 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "./ft_printf/includes/ft_printf.h"
#include "./includes/fdf.h"

// Algo de bresenham
/*
int	deal_key(int key, void *param)
{
	ft_putchar('X');
	//param ?
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0x1FFFFF);
	return (0);
}
*/

void	fill_pixel(unsigned int *img, int x, int y)//, int color)
{
	int i;

	i = 0;
	if (x)
		;
	if (y)
		;
	/* lignes RGB verticales _____________________
	while (i < 800 * 600 * 4)
	{
		if (((i % 4) / 3) != 1 && (i * 4 % 25) == 0)
			img[i] = (char)255;
		i++;
	}
	*/
	/* lignes verticales multiple 10______________
	while (i < 800 * 600)
	{
		if (i % 10 == 0)
			img[i] = 0xFFFFFF;
		if ((i  == 0)
			img[i] = 0xFFFFFF;
		i++;
	}
	*/
	img[y * WIN_WIDTH + x] = 0xFFFFFF;
}

void	draw_lines(unsigned int *img, int width, int height)
{
	int x;
	int y;

	x = 0;
	y = 0;
	/*
	while (y < 600)
	{
		while (x < 800)
		{
				if (x % 5 == 0)		
					fill_pixel(img, x, y);//, 0xFFFFFF);
			x++;
		}
		y++;
		x = 0;
	}
	*/
	while (x < width)
	{
		while (y < height)
		{
				if ((x > 100 && x < 700) && (y > 100 && y < 500) &&(y % 10 == 0 && x % 10 == 0))
					fill_pixel(img, x, y);//, 0xFFFFFF);
			y++;
		}
		x++;
		y = 0;
	}
}
int main()
{
	t_mlx	*data;
	int		img_width;
	int		img_height;
	//t_img	*imlx; ?

	img_width = WIN_WIDTH;
	img_height = WIN_HEIGHT;
	if (!(data = ft_memalloc(sizeof(t_mlx))))
			return(-1);
	data->mlx_ptr = mlx_init();
	data->win = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, img_width, img_height);
	data->img.img = (unsigned int*)mlx_get_data_addr(data->img.img_ptr,
			&(data->img.size_l), &(data->img.bpp), &(data->img.endian));
	draw_lines(data->img.img, img_width, img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->img.img_ptr, 0, 0);
	//mlx_pixel_put(data->mlx_ptr, data->win, 250, 250, 0xFFFFFF);
	//mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(data->mlx_ptr);
}
