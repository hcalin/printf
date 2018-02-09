/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:37:46 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 15:13:36 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			maxx(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void		x_put_zero(t_arg aux, char *p)
{
	int		i;

	i = 0;
	while (++i <= (int)(aux.prec - ft_strlen(p)))
	{
		ft_putchar('0');
		g_size++;
	}
	ft_putstr(p);
}

void		hexa_putx(int hash, int zero, int ok, int x)
{
	if (hash && !zero && !ok)
	{
		if (x)
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
}
