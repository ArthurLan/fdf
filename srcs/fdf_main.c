/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:05:08 by alanter           #+#    #+#             */
/*   Updated: 2018/07/19 18:00:15 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Algo de bresenham

int	deal_key(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->win);
		fdf_free(mlx);
		exit(0);
	}
	ft_printf("Voilà ma touche : %d\n", key);
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0x1FFFFF);
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Usage : ./fdf [file]\n");
			return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
			return(-1);
	init_param(mlx, fd, argv[1]);
	fdf_draw(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	mlx_key_hook(mlx->win, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
	fdf_free(mlx);
}
