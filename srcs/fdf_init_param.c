/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:22:29 by alanter           #+#    #+#             */
/*   Updated: 2018/07/24 23:57:32 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_map_val(t_param *param, int x, int y)
{
	int k;

	k = 0;
	param->coord = ft_memalloc(sizeof(t_coord*) * param->map_h);
	while (++x < param->map_h)
	{
		param->coord[x] = ft_memalloc(sizeof(t_coord) * param->map_l);
		while (++y < param->map_l)
		{
			param->coord[x][y].z = ft_atoi(&param->map[x][k]);
			if (param->coord[x][y].z > 4096 || param->coord[x][y].z < -4096)
				param->error = 5;
			while (param->map[x][k] && param->map[x][k] != ' ')
				k++;
			while (param->map[x][k] && !(ft_isdigit(param->map[x][k])))
				k++;
		}
		free(param->map[x]);
		y = -1;
		k = 0;
	}
	free(param->map);
}

int			init_hl_map(t_param *p, int *fd, int ret)
{
	char	*line;

	line = NULL;
	while ((ret = get_next_line(*fd, &line))
			&& p->map_h < 4096 && p->map_l < 4096)
	{
		p->map_h++;
		if (!(p->map_l))
			p->map_l = ft_nbrcounter(line, ' ');
		if ((size_t)p->map_l != ft_nbrcounter(line, ' ') && (p->error = 2))
			return (2);
		ft_memdel((void*)&line);
	}
	if (!(p->map_l) && (p->error = 1))
		return (1);
	if ((p->map_h == 4096 || p->map_l == 4096) && (p->error = 3))
		return (3);
	if ((p->map_l == 1 || p->map_h == 1) && (p->error = 4))
		return (4);
	if (ret == -1)
		return (-1);
	ft_memdel((void*)&line);
	return (0);
}

int			copy_map(t_mlx *mlx, int *fd, char *argv, int i)
{
	close(*fd);
	*fd = open(argv, O_RDONLY);
	if (*fd < 0)
		return (-1);
	fdf_scale_map(&mlx->param);
	if (!(mlx->param.map = malloc(sizeof(char*) * (mlx->param.map_h))))
		return (-1);
	while (++i < mlx->param.map_h)
	{
		if (get_next_line(*fd, &mlx->param.map[i]) < 0)
			return (-1);
	}
	return (0);
}

int			init_param(t_mlx *mlx, int fd, char *argv)
{
	mlx->param.less = 1;
	mlx->param.zoom = 2;
	if (mlx->param.map_h)
		fdf_scale_map(&mlx->param);
	if (!(mlx->param.map_h))
	{
		mlx->mlx_ptr = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
		mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		mlx->img.img = (unsigned int*)mlx_get_data_addr(mlx->img.img_ptr,
			&(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));
		if (init_hl_map(&mlx->param, &fd, 0) < 0)
			return (-1);
		if (fdf_checker(mlx) < 0)
			return (-1);
		if (copy_map(mlx, &fd, argv, -1) < 0)
			return (-1);
		init_map_val(&mlx->param, -1, -1);
		if (fdf_checker(mlx) < 0)
			return (-1);
	}
	return (0);
}
