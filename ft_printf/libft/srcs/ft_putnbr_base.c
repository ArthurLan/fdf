/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:44:16 by alanter           #+#    #+#             */
/*   Updated: 2018/05/01 20:47:30 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_base(long nbr, int base)
{
	if (nbr > base)
	{
		ft_putnbr_base(nbr / base, base);
		ft_putnbr_base(nbr % base, base);
	}
	else
	{
		if (nbr < 10)
			ft_putnbr(nbr);
		else
			ft_putchar('a' + nbr - 10);
	}
}
