/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_voice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 14:35:04 by alanter           #+#    #+#             */
/*   Updated: 2018/07/24 19:14:14 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_voice(t_mlx *mlx)
{
	if (mlx->param.voice == 1)
		system("say Voice active, great !");
	else if (mlx->param.voice == 34 && (mlx->param.voice = -1))
		system("say Zooming !");
	else if (mlx->param.voice == 122 && (mlx->param.voice = -2))
		system("say moving map !");
	else if (mlx->param.voice == 69 && (mlx->param.voice = -3))
		system("say Height changed !");
	else if (mlx->param.voice == 15 && (mlx->param.voice = -4))
		system("say Resetting map !");
	else if (mlx->param.voice == 24 && (mlx->param.voice = -5))
		system("say Densification changed !");
	else if (mlx->param.voice == 83)
		system("say Color inactive!");
	else if (mlx->param.voice == 84)
		system("say Color active first mode!");
	else if (mlx->param.voice == 85)
		system("say Color active second mode!");
	else if (mlx->param.voice == 8 && mlx->param.compressor)
		system("say Compression active !");
	else if (mlx->param.voice == 8)
		system("say Compression inactive !");
}
