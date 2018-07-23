/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:05:08 by alanter           #+#    #+#             */
/*   Updated: 2018/07/23 20:24:39 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Algo de bresenham

void	ft_new_image(t_mlx *mlx)
{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
		mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
   		mlx->img.img = (unsigned int*)mlx_get_data_addr(mlx->img.img_ptr,
				&(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));
		fdf_draw(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
}

int	deal_key(int key, t_mlx *mlx, int fd, char *argv)
{
	if (fdf_bonus(key, mlx, fd, argv))
		ft_new_image(mlx);
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <file>\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: File not found.");
		return (-1);
	}
	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return(-1);
	if (init_param(mlx, fd, argv[1]) < 0)
	{
		//fdf_free(mlx);
		return (-1);
	}
	fdf_draw(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	mlx_key_hook(mlx->win, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
	//fdf_free(mlx);
	return (0);
}
