/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:09:25 by alanter           #+#    #+#             */
/*   Updated: 2018/07/17 20:27:13 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

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
	{
		ft_putendl("1");	
		return(0);
	}
	if (round(-(p->map_h - 1) * p->scale + p->offset_x) < WIN_WIDTH / 10)
	{
		ft_putendl("2");	
		return(0);
	}
	if (round((p->map_l + p->map_h - 2) / 2. * p->scale + p->offset_y)
			> WIN_HEIGHT - WIN_HEIGHT / 10)
	{
		ft_putendl("3");	
		return(0);
	}
	if (round((p->map_l - 1) * p->scale + p->offset_x)
		   	> WIN_WIDTH - WIN_WIDTH / 10)
	{
		ft_putendl("4");	
		return(0);
	}
	return(1);
}

void ft_scale_map(t_param *param)
{
	const float x = param->map_l / 2.;
	const float y = param->map_h / 2.;
	param->scale = 0.1;
	param->offset_x = -((x - y) * param->scale - WIN_WIDTH / 2.); 
	param->offset_y = -(((x + y) / 2.) * param->scale / 1.3 - WIN_HEIGHT / 2.); 
	printf("offset_x : %f\noffset_y : %f\n", param->offset_x, param->offset_y);
	while (check_limit(param))
	{
		param->scale += 0.01;
		param->offset_x = -((x - y) * param->scale - WIN_WIDTH / 2.); 
		param->offset_y = -((x + y) / 2. * param->scale - WIN_HEIGHT / 2.);
	printf("offset_x : %f\noffset_y : %f\n", param->offset_x, param->offset_y);
	}
}
