/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:04:25 by alanter           #+#    #+#             */
/*   Updated: 2018/07/21 23:18:44 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_free(t_mlx *mlx)
{
	int i;

	i = mlx->param.map_h;
	//ft_memdel((void*)&mlx->mlx_ptr);
	//ft_memdel((void*)&mlx->win);
	ft_memdel((void*)&mlx->img.img_ptr);
	ft_memdel((void*)&mlx->img.img);
	ft_memdel((void*)&mlx->img);
	//while (i--)
	//	ft_memdel((void*)&mlx->param.map[i]);
	//ft_memdel((void*)&mlx->param.map);
	ft_memdel((void*)&mlx->param);
	ft_memdel((void*)&mlx);
}
