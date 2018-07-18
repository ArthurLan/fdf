/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:05:08 by alanter           #+#    #+#             */
/*   Updated: 2018/07/18 19:33:25 by alanter          ###   ########.fr       */
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


void	write_map_val(t_param param)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < param.map_h)
	{
		while (j < param.map_l)
		{
			ft_printf("tab[%d][%d] = %d\n", i, j, param.map_val[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}


void	init_map_val(t_param *param)
{
	//garder param->map[i] avec une réassign avant de l'incrémenter, libérer à la fin
	int i;
	int j;

	i = 0;
	j = 0;
	param->map_val = ft_memalloc(sizeof(int*) * param->map_h);
	while (i < param->map_h)
	{
		param->map_val[i] = ft_memalloc(sizeof(int*) * param->map_l);
		while (j < param->map_l)
		{
			//ici : ptr = param->map[i];
			while(!(ft_isdigit(*param->map[i])))
				param->map[i]++;
			param->map_val[i][j] = ft_atoi(param->map[i]);
			while(ft_isdigit(*param->map[i]))
			{
				param->map[i]++;
				//ft_printf("Voilà ma map pour i = [%d] : [%s]\n", i, param->map[i]++);
			}
			j++;
			//et là : free(ptr);
		}
		j = 0;
		i++;
	}
	write_map_val(*param);
}

static  int     wordcounter(char *s2, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (ft_strlen(s2) != 0)
	{
		if (s2[0] != c)
		{
			count++;
			i++;
		}
		while (s2[i] != 0)
		{
			if (s2[i - 1] == c && s2[i] != c)
				count++;
			i++;
		}
	}
	return (count);
}

int static init_struct(t_mlx *mlx, int fd, char *argv)
{
	int	lines;
	int raws;
	char *line;
	int		i;

	lines = 0;
	raws = 0;
	i = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "## FDF - alanter##");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.img = (unsigned int*)mlx_get_data_addr(mlx->img.img_ptr,
	&(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));
	
	while ((get_next_line(fd, &line)))
	{
		lines++;
		if (!(raws))
			raws = wordcounter(line, ' ');
		//ft_memdel((void*)&line);
	}
	close(fd);
	fd = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	mlx->param.map_l = raws;
	mlx->param.map_h = lines;
	ft_scale_map(&mlx->param);
	mlx->param.map = ft_memalloc(sizeof(char*) * lines);
	while((get_next_line(fd, &mlx->param.map[i])))
		i++;
	init_map_val(&mlx->param);
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (-1);
	}
	else
	{
		ft_printf("Usage : ./fdf [file]\n");
			return (-1);
	}
	//mlx_pixel_put(mlx->mlx_ptr, mlx->win, 250, 250, 0xFFFFFF);
	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
			return(-1);
	init_struct(mlx, fd, argv[1]);
	draw_point(mlx->img.img, &mlx->param, mlx->param.map_l, mlx->param.map_h);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	mlx_key_hook(mlx->win, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
	fdf_free(mlx);
}
