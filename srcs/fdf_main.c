/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 22:13:24 by alanter           #+#    #+#             */
/*   Updated: 2018/07/25 00:05:14 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_putstr(t_mlx *mlx)
{
	int c;

	c = 0xFFFFFF;
	mlx_string_put(mlx->mlx_ptr, mlx->win, 18, 15, c, "###Options###");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 16, 40, c, "Arrows : Move");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 16, 60, c, "+ & -  : Change height");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 16, 80, c, "I & O  : Zoom");
	mlx_string_put(mlx->mlx_ptr, mlx->win,
			16, 100, c, "_ & =  : Densification");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 16, 122, c, "    C  : Compressor");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 16, 142, c, "    R  : Reset");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 16, 162, c, "    V  : Voice");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 16, 182, c, "<esc>  : Quit");
}

void		ft_new_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.img = (unsigned int*)mlx_get_data_addr(mlx->img.img_ptr,
			&(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));
	fdf_draw(mlx, -1, -1);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	fdf_putstr(mlx);
}

int			deal_key(int key, t_mlx *mlx, int fd, char *argv)
{
	if (fdf_bonus(key, mlx, fd, argv))
		ft_new_image(mlx);
	return (0);
}

int			fdf_checker(t_mlx *mlx)
{
	if (mlx->param.error == 1)
		ft_printf("Error: No data found.\n");
	else if (mlx->param.error == 2)
		ft_printf("Error: Found wrong line length. Exiting.\n");
	else if (mlx->param.error == 3)
		ft_printf("Error: Map is too big. Size max is 4096 x 4096.\n");
	else if (mlx->param.error == 4)
		ft_printf("Error: Map must be at least 2 x 2.\n");
	else if (mlx->param.error == 5)
		ft_printf("Error: Map values must be less between -4096 and 4096.\n");
	else
		return (0);
	return (-1);
}

int			main(int argc, char **argv)
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
		ft_printf("Error: File not found. Check permissions.\n");
		return (-1);
	}
	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (-1);
	if (init_param(mlx, fd, argv[1]) < 0)
		return (-1);
	fdf_draw(mlx, -1, -1);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	fdf_putstr(mlx);
	mlx_key_hook(mlx->win, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
