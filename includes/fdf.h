/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:06:02 by alanter           #+#    #+#             */
/*   Updated: 2018/07/24 22:29:13 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../ft_printf/includes/ft_printf.h"
# include "../ft_printf/includes/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define WIN_WIDTH 1350
# define WIN_HEIGHT 780

typedef struct	s_img
{
	void			*img_ptr;
	unsigned int	*img;
	int				size_l;
	int				bpp;
	int				endian;
}				t_img;

typedef struct	s_coord
{
	int		z;
	int		isox;
	int		isoy;
	int		color;
}				t_coord;

typedef struct	s_param
{
	char	**map;
	float	scale;
	float	offset_x;
	float	offset_y;
	int		map_l;
	int		map_h;
	t_coord	**coord;
	int		error;
	int		coef;
	int		less;
	int		compressor;
	int		movex;
	int		movey;
	int		zoom;
	int		coloredge;
	int		voice;
	int		voice_active;
}				t_param;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	t_param		param;
}				t_mlx;

void			fdf_draw(t_mlx *mlx, int x, int y);
int				fdf_checker(t_mlx *mlx);
int				init_param(t_mlx *mlx, int fd, char *argv);
void			fdf_scale_map(t_param *param);
int				fdf_bonus(int key, t_mlx *mlx, int fd, char *argv);
int				fdf_bonusb(int key, t_mlx *mlx, int fd, char *argv);
void			fdf_voice(t_mlx *mlx);

#endif
