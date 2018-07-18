/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:06:02 by alanter           #+#    #+#             */
/*   Updated: 2018/07/18 19:33:26 by alanter          ###   ########.fr       */
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

/*
 *  Defines for the width and height of your window. I suggest you to do the same so
 *   you can change easily the size of your window later if needed.
 *   */
# define WIN_WIDTH 800
# define WIN_HEIGHT 400

/*
 *  Here I built a struct of the MLX image :
 *   It contains everything you need.
 *    - img_ptr to store the return value of mlx_new_image
 *     - data to store the return value of mlx_get_data_addr
 *      - the 3 other variables are pretty much useless, but you'll need
 *       them in the prototype of mlx_get_data_addr (see the man page for that)
 *        */
typedef struct	s_img
{
	void		*img_ptr;
	unsigned int			*img; 
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;
				
/*
 * 	 Here is my main struct containing every variables needed by the MLX.
  - mlx_ptr stores the return value of mlx_init
  - win stores the return value of mlx_new_window
  - img will store everything we need for the image part, the struct is described above.
 */

typedef struct	s_param
{
	int		**map_val;
	char	**map;
	float	scale;
	float	offset_x;
	float	offset_y;
	int	map_l;
	int map_h;

}				t_param;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	t_param		param;
}				t_mlx;


void	draw_point(unsigned int *img, const t_param *param, int x, int y);
void 	ft_scale_map(t_param *param);
void	fdf_free(t_mlx *mlx);
#endif
