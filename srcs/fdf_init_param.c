/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:22:29 by alanter           #+#    #+#             */
/*   Updated: 2018/07/21 23:33:54 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Check limit verifiy the marging for :
** - {0, 0};
** - {0, map_h};
** - {map_l, map_h};
** - {map_l, 0};
*/

static int check_limit(const t_param *p)
{
	if (round(p->offset_y) < WIN_HEIGHT / 10)
		return(0);
	if (round(-(p->map_h - 1) * p->scale + p->offset_x) < WIN_WIDTH / 10)
		return(0);
	if (round((p->map_l + p->map_h - 2) / 2. * p->scale + p->offset_y)
			> WIN_HEIGHT - WIN_HEIGHT / 10)
		return(0);
	if (round((p->map_l - 1) * p->scale + p->offset_x)
		   	> WIN_WIDTH - WIN_WIDTH / 10)
		return(0);
	return(1);
}

void ft_scale_map(t_param *param)
{
	const float x = param->map_l / 2.;
	const float y = param->map_h / 2.;
	param->scale = 0.1;
	param->offset_x = -((x - y) * param->scale - WIN_WIDTH / 2.); 
	param->offset_y = -(((x + y) / 2.) * param->scale / 1.3 - WIN_HEIGHT / 2.); 
	while (check_limit(param))
	{
		param->scale += 0.01;
		param->offset_x = (WIN_WIDTH / 2. - (x - y) * param->scale); 
		//param->offset_y = -((x + y) / 2. * param->scale - WIN_HEIGHT / 2.);
		param->offset_y = (WIN_HEIGHT / 2. - (x + y) / 2. * param->scale);
	}
}

/*
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
			ft_printf("tab[%d][%d] = %d\n", i, j, param.coord[i][j].z);
			j++;
		}
		j = 0;
		i++;
	}
}
*/

void	init_map_val(t_param *param)
{
	//garder param->map[i] avec une réassign avant de l'incrémenter, libérer à la fin
	int i;
	int j;

	i = -1;
	j = -1;
	param->coord = ft_memalloc(sizeof(t_coord*) * param->map_h);
	while (++i < param->map_h)
	{
		param->coord[i] = ft_memalloc(sizeof(t_coord) * param->map_l);
		while (++j < param->map_l)
		{
			//ici : ptr = param->map[i];
			param->coord[i][j].z = ft_atoi(param->map[i]);
			while(ft_isdigit(*param->map[i]))
				param->map[i]++;
			while(!(ft_isdigit(*param->map[i])))
				param->map[i]++;
				//ft_printf("Voilà ma map pour i = [%d] : [%s]\n", i, param->map[i]++);
			//et là : free(ptr);
		}
		j = -1;
	}
	//write_map_val(*param);
}
int		init_hl_map(t_mlx *mlx, int *fd, char *argv, int i)
{
	char *line;

	while ((get_next_line(*fd, &line)) && mlx->param.map_h < 2147483647)
	{
		mlx->param.map_h++;
		if (!(mlx->param.map_l))
			mlx->param.map_l = ft_wordcounter(line, ' ');
		if (mlx->param.map_l != ft_wordcounter(line, ' ') && (mlx->param.error = 2))
			return(2);
		//ft_memdel((void*)&line);
	}
	if ((mlx->param.map_h == 2147483647 || mlx->param.map_l == 2147483647)
			&& (mlx->param.error = 3))
		return (3);
	if (!(mlx->param.map_l) && (mlx->param.error = 1))
		return (1);
	close(*fd);
	*fd = open(argv, O_RDONLY);
	if (*fd < 0)
		return (-1);
	ft_scale_map(&mlx->param);
	mlx->param.map = ft_memalloc(sizeof(char*) * mlx->param.map_h);
	while((get_next_line(*fd, &mlx->param.map[i])))
		i++;
	return (0);
}

int init_param(t_mlx *mlx, int fd, char *argv)
{
	mlx->param.map_l = 0;
	mlx->param.map_h = 0;
	mlx->param.error = 0;
	mlx->param.coef = 10;
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.img = (unsigned int*)mlx_get_data_addr(mlx->img.img_ptr,
	&(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));
	if (init_hl_map(mlx, &fd, argv, 0) < 0)
		return (-1);
	if (fdf_checker(mlx) < 0)
		return (-1);
	init_map_val(&mlx->param);
	return (0);
}
