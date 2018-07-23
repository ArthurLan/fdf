/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:18:36 by alanter           #+#    #+#             */
/*   Updated: 2018/07/11 20:22:18 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_flag(char c)
{
	if (ft_strchr(".0123456789#-+ hljz", c) != NULL)
		return (1);
	else
		return (0);
}

void	back_zero(t_printf *data, int len)
{
	if (CZERO > 0)
		BACKZ = (BACKZ > 0) ? BACKZ + CZERO : ft_strlen(RET) + CZERO;
	if (BACKZ > 0 && CZERO == 0)
		BACKZ += len;
	CZERO = 0;
}

void	store_cleanstr(t_printf *data, int i, int j)
{
	char	*tmp;
	int		len;

	tmp = TO_ADD;
	TO_ADD = ft_strndup(&(STR[j]), i - j);
	len = ft_strlen(TO_ADD);
	RET = ft_ultim_join(&RET, &TO_ADD, BACKZ, 0);
	back_zero(data, len);
	if (tmp != NULL)
		free(tmp);
}

void	parsing(t_printf *data, va_list lst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (STR[i] != 0)
	{
		j = i;
		while (STR[i] != '%' && STR[i] != 0)
			i++;
		if (i != j)
			store_cleanstr(data, i, j);
		if (STR[i] == '%')
		{
			i++;
			j = i;
			while (STR[i] != 0 && ft_is_flag(STR[i]))
				i++;
			if (STR[i] != 0 && ft_strchr("sSpdDioOuUxXcC%", STR[i]))
			{
				convert(data, lst, ++i, j);
				back_zero(data, 0);
			}
		}
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		lst;
	t_printf	*data;
	int			ret;

	if (!((char*)format))
		return (-1);
	data = ft_memalloc(sizeof(t_printf));
	STR = ft_strdup(format);
	BACKZ = 0;
	CZERO = 0;
	va_start(lst, format);
	parsing(data, lst);
	ret = (BACKZ) ? BACKZ : ft_strlen(RET);
	if (BACKZ)
		write(1, RET, BACKZ);
	else
		write(1, RET, ret);
	if (RET)
		free(RET);
	if (STR)
		free(STR);
	free(data);
	va_end(lst);
	return (ret);
}
