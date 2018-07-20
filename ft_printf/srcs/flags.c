/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:36:53 by alanter           #+#    #+#             */
/*   Updated: 2018/07/13 09:41:57 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** FLAG = tab of int to deal with flags
** FLAG[0] = #;
** FLAG[1] = +;
** FLAG[2] = space;
** FLAG[3] = -;
** FLAG[4] = 0;
** FLAG[5] = width;
** FLAG[6] = precision;
*/

void	scan_flag(t_printf *data, char *scan)
{
	int state;

	state = 0;
	while (*scan != 0)
	{
		state = (state == 2 && *scan == '.') ? 3 : state;
		state = (*scan == '.' && state < 2) ? 2 : state;
		if (*scan == '#')
			FLAG[0] = 1;
		else if (*scan == '+' && !(NEG))
			FLAG[1] = 1;
		else if (*scan == ' ' && (ft_strchr(SCAN, '+') == NULL))
			FLAG[2] = 1;
		else if (*scan == '-')
			FLAG[3] = 1;
		else if (state == 0 && *scan == '0' && (ft_strchr(SCAN, '-') == NULL))
			FLAG[4] = 1;
		else if (state == 0 && *scan > '0' && *scan <= '9' && (state = 1))
			FLAG[5] = ft_atoi(scan);
		else if (state == 2 && *scan > '0' && *scan <= '9' && (state = 3))
			FLAG[6] = ft_atoi(scan) != 0 ? ft_atoi(scan) : -1;
		scan++;
	}
	FLAG[6] = (((state == 2 || state == 3) && FLAG[6] == 0) ?
			-1 : FLAG[6]);
}

void	width(t_printf *data)
{
	int zero_space;

	FLAG[4] = (FLAG[6] < FLAG[5] && !(NEG) && FLAG[6] > 0) ? 0 : FLAG[4];
	zero_space = (FLAG[4] == 1) ? '0' : ' ';
	ADD_FLAG = ft_memalloc(FLAG[5] - ft_strlen(TO_ADD) + 1);
	ADD_FLAG = ft_memset(ADD_FLAG, zero_space, FLAG[5] - ft_strlen(TO_ADD));
	if (FLAG[3] == 0)
		TO_ADD = ft_ultim_join(&ADD_FLAG, &TO_ADD, 0, 0);
	else
		TO_ADD = ft_ultim_join(&TO_ADD, &ADD_FLAG, 0, 0);
	if (ft_strchr(TO_ADD, 'x') > ft_strchr(TO_ADD, '0'))
		ft_switchar(ft_strchr(TO_ADD, 'x'), ft_strchr(TO_ADD, '0') + 1);
	if (ft_strchr(TO_ADD, '+') > ft_strchr(TO_ADD, '0'))
		ft_switchar(ft_strchr(TO_ADD, '+'), ft_strchr(TO_ADD, '0'));
}

void	flag_char(t_printf *data)
{
	char *tmp;

	tmp = TO_ADD;
	FLAG[6] = (FLAG[6] == -1) ? 0 : FLAG[6];
	if (ft_strchr(SCAN, '.') && (ft_strlen(TO_ADD) > (size_t)FLAG[6]))
	{
		TO_ADD = ft_strndup(TO_ADD, FLAG[6]);
		free(tmp);
	}
	if (FLAG[5] > 0 && (ft_strlen(TO_ADD) < (size_t)FLAG[5]))
		width(data);
}

void	flag_int(t_printf *data)
{
	if (FLAG[0] == 1 && (TYPE == 'o' || TYPE == 'O') && (ft_atoi(TO_ADD) != 0))
		TO_ADD = ft_statjoin("0", &TO_ADD, 0, 0);
	if (FLAG[6] > 0 && FLAG[6] > (int)ft_strlen(TO_ADD))
	{
		ADD_FLAG = ft_memalloc(FLAG[6] - ft_strlen(TO_ADD) + 1 + NEG);
		ADD_FLAG = ft_memset(ADD_FLAG, '0', FLAG[6] - ft_strlen(TO_ADD) + NEG);
		TO_ADD = ft_ultim_join(&ADD_FLAG, &TO_ADD, 0, 0);
	}
	if (FLAG[6] == -1 && ft_strchr("idDoOxX", TYPE) && (ft_atoi(TO_ADD) == 0))
	{
		free(TO_ADD);
		TO_ADD = (ft_strchr("oO", TYPE) && FLAG[0] == 1) ?
			ft_strdup("0") : ft_strdup("");
	}
	if ((FLAG[0] == 1 && (TYPE == 'x' || TYPE == 'X')) || TYPE == 'p')
		TO_ADD = (ft_atoi(TO_ADD) > 0 || TYPE == 'p') ?
			ft_statjoin("0x", &TO_ADD, 0, 0) : TO_ADD;
	if (FLAG[1] == 1 && ft_strchr("idD", TYPE) && (ft_atoi(TO_ADD) >= 0))
		TO_ADD = ft_statjoin("+", &TO_ADD, 0, 0);
	if (FLAG[2] == 1 && ft_strchr("idD", TYPE) && (ft_atoi(TO_ADD) >= 0))
		TO_ADD = ft_statjoin(" ", &TO_ADD, 0, 0);
	if (FLAG[5] > 0 && FLAG[5] > (int)ft_strlen(TO_ADD))
		width(data);
}

void	flags(t_printf *data)
{
	FLAG = ft_memalloc(sizeof(int) * 8);
	if (ft_strlen(SCAN) > 1 || TYPE == 'p')
	{
		scan_flag(data, SCAN);
		if (ft_strchr("idDuUoOxXp", TYPE))
			flag_int(data);
	}
	if (ft_strchr(TO_ADD, '-') > ft_strchr(TO_ADD, '0'))
		ft_switchar(ft_strchr(TO_ADD, '-'), ft_strchr(TO_ADD, '0'));
	if (ft_strchr(TO_ADD, ' ') > ft_strchr(TO_ADD, '0') && FLAG[3] == 0)
		ft_switchar(ft_strchr(TO_ADD, ' '), ft_strchr(TO_ADD, '0'));
	if (ft_strchr("cCsS", TYPE))
		flag_char(data);
	if (TYPE == 'X')
		ft_strupcase(TO_ADD);
	if (TYPE == 'u' && ft_strchr(SCAN, '.') && FLAG[6] <= 0)
		ft_cleanfree(&TO_ADD);
	if (TYPE == 'p' && ft_strchr(SCAN, '.') && FLAG[6] <= 0)
		TO_ADD[2] = 0;
	if (TYPE == '%')
	{
		FLAG[6] = 0;
		flag_int(data);
	}
	free(FLAG);
}
