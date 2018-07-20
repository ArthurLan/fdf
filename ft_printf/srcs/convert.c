/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:43:17 by alanter           #+#    #+#             */
/*   Updated: 2018/07/11 20:22:22 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ---- SPEC = int to deal with specifiers ----
**
**---- hh	1
**---- h	2
**---- l	3
**---- ll	4
**---- j	5
**---- z	6
*/

void	store_di(t_printf *data, va_list lst)
{
	ft_cleanfree(&TO_ADD);
	SPEC = (TYPE == 'D') ? 4 : SPEC;
	if (SPEC == 0)
		TO_ADD = ft_itoa(va_arg(lst, int));
	else if (SPEC == 1)
		TO_ADD = ft_itoa((char)(va_arg(lst, int)));
	else if (SPEC == 2)
		TO_ADD = ft_itoa((short int)(va_arg(lst, int)));
	else if (SPEC == 3)
		TO_ADD = ft_lltoa_base(va_arg(lst, long int), 10);
	else if (SPEC == 4)
		TO_ADD = ft_lltoa_base(va_arg(lst, long long int), 10);
	else if (SPEC == 5)
		TO_ADD = ft_lltoa_base(va_arg(lst, intmax_t), 10);
	else if (SPEC == 6)
		TO_ADD = ft_lltoa_base(va_arg(lst, size_t), 10);
	NEG = (ft_atoll(TO_ADD) < 0) ? 1 : 0;
}

void	store_uoxp(t_printf *data, va_list lst, int base)
{
	ft_cleanfree(&TO_ADD);
	SPEC = (TYPE == 'O') ? 3 : SPEC;
	if (SPEC == 0 && TYPE != 'p' && TYPE != 'U')
		TO_ADD = ft_ulltoa_base(va_arg(lst, unsigned int), base);
	else if (SPEC == 1 && TYPE != 'U')
		TO_ADD = ft_ulltoa_base((unsigned char)(va_arg(lst, int)), base);
	else if (SPEC == 2 && TYPE != 'U')
		TO_ADD = ft_ulltoa_base((unsigned short int)(va_arg(lst, int)), base);
	else if (SPEC == 3 || TYPE == 'p')
		TO_ADD = ft_ulltoa_base(va_arg(lst, unsigned long int), base);
	else if (SPEC == 4 || TYPE == 'U')
		TO_ADD = ft_ulltoa_base(va_arg(lst, unsigned long long int), base);
	else if (SPEC == 5)
		TO_ADD = ft_ulltoa_base(va_arg(lst, uintmax_t), base);
	else if (SPEC == 6)
		TO_ADD = ft_ulltoa_base(va_arg(lst, size_t), base);
}

void	store_cs(t_printf *data, va_list lst)
{
	ft_cleanfree(&TO_ADD);
	if ((SPEC == 3 && TYPE == 'c') || TYPE == 'C')
		TO_ADD = ft_wctostr(va_arg(lst, wint_t));
	else if ((SPEC == 3 && TYPE == 's') || TYPE == 'S')
		TO_ADD = ft_wtostr(va_arg(lst, wchar_t *));
	else if (TYPE == 'c')
		TO_ADD = ft_ctostr((char)(va_arg(lst, int)));
	else
		TO_ADD = ft_strdup(va_arg(lst, char *));
	if (TO_ADD == NULL && ft_strchr("sS", TYPE))
		TO_ADD = ft_strdup("(null)");
	if (*TO_ADD == 0 && ft_strchr("cC", TYPE))
		CZERO += 1;
}

void	type_analyse(t_printf *data, int i, int j)
{
	char *tmp;

	SPEC = 0;
	tmp = SCAN;
	while (j < i && SPEC == 0)
	{
		if (STR[j] == 'h')
			SPEC = (ft_strrchr(SCAN, 'h') != SCAN) ? 1 : 2;
		if (STR[j] == 'l')
			SPEC = (ft_strrchr(SCAN, 'l') != SCAN) ? 4 : 3;
		if (STR[j] == 'j')
			SPEC = 5;
		if (STR[j] == 'z')
			SPEC = 6;
		j++;
		SCAN++;
	}
	SCAN = tmp;
}

void	convert(t_printf *data, va_list lst, int i, int j)
{
	int base;

	SPEC = 0;
	NEG = 0;
	TYPE = STR[i - 1];
	if (ft_strchr("oO", TYPE))
		base = 8;
	else
		base = (ft_strchr("xXp", TYPE)) ? 16 : 10;
	SCAN = ft_strndup(&(STR[j]), i - j);
	if (ft_strlen(SCAN) > 1)
		type_analyse(data, i, j);
	if (TYPE == 's' || TYPE == 'S' || TYPE == 'c' || TYPE == 'C')
		store_cs(data, lst);
	else if (TYPE == 'd' || TYPE == 'i' || TYPE == 'D')
		store_di(data, lst);
	else if (ft_strchr("oOuUxXp", TYPE) != NULL)
		store_uoxp(data, lst, base);
	else if (TYPE == '%')
		TO_ADD = ft_strdup("%");
	flags(data);
	RET = ft_ultim_join(&RET, &TO_ADD, BACKZ, CZERO);
	ft_cleanfree(&SCAN);
}
