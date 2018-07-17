/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:05:08 by alanter           #+#    #+#             */
/*   Updated: 2018/07/17 20:27:17 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*
void	init_tab(t_img img)
{
	int i;
	int j;

	i = 0;
	j = 0;
	img.tab = ft_memalloc(sizeof(int*) * 5);
	while (i < 5)
	{
		img.tab[i] = ft_memalloc(sizeof(int*) * 5);
		while (j < 5)
		{
			img.tab[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	*/
	/*
	i = 0;
	while (i < 5)
	{
		while (j < 5)
		{
			ft_printf("tab[%d][%d] = %d\n", i, j, img.tab[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}
	*/

int main()
{
	t_mlx	*mlx;
	int		img_width;
	int		img_height;

	img_width = WIN_WIDTH;
	img_height = WIN_HEIGHT;
	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
			return(-1);

	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, img_width, img_height);
	mlx->img.img = (unsigned int*)mlx_get_data_addr(mlx->img.img_ptr,
	&(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));

//	init_tab(mlx->img);

	mlx->param.map_l = 40;
	mlx->param.map_h = 40;
	ft_scale_map(&mlx->param);
	printf("%f\n", mlx->param.scale);
	draw_point(mlx->img.img, &mlx->param, mlx->param.map_l, mlx->param.map_h);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);

	//mlx_pixel_put(mlx->mlx_ptr, mlx->win, 250, 250, 0xFFFFFF);
	//mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx->mlx_ptr);
}
