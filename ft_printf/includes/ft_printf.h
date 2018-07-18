/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:05:12 by alanter           #+#    #+#             */
/*   Updated: 2018/07/11 20:22:12 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"
# include <wchar.h>

/*
**	-- Every macro is used to access data structure MAJ = data->maj --
**
**	STR		= copy from format
**	RET		= string to print by printf
** 	TO_ADD	= string to add at the end of the result piece by piece
** 	SCAN 	= data to analyse, ex : %-.9d
**	TYPE	= type from SCAN,  ex : d
**	FLAG	= flag "#+ -0" precision and padding, ex : -.9
**	SPEC	= type conversion "hh, h, l, ll..."
**	NEG		= boolean, negative or positive
**	CZERO	= used when C or lc is \0
**	BACKZ	= size with \0
*/

# define STR data->str
# define RET data->ret
# define TO_ADD data->to_add
# define ADD_FLAG data->add_flag
# define SCAN data->scan
# define TYPE data->type
# define FLAG data->flag
# define SPEC data->spec
# define NEG data->neg
# define CZERO data->czero
# define BACKZ data->backz

typedef struct	s_printf
{
	char				*str;
	char				*ret;
	char				*to_add;
	char				*add_flag;
	char				*scan;
	char				type;
	int					*flag;
	int					spec;
	int					neg;
	int					czero;
	unsigned long long	backz;
}				t_printf;

int				ft_printf(const char *format, ...);
void			convert(t_printf *data, va_list lst, int i, int j);
void			flags(t_printf *data);

#endif
