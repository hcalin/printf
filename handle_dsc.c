/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dsc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:03:58 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 15:27:27 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_int(va_list *args, t_arg aux)
{
	char			*pt;
	long long int	nb;

	if (aux.l || aux.ll || aux.z)
		nb = get_number_ll(args, aux);
	else
		nb = get_number_h(args, aux);
	if ((aux.nb <= ft_nbrlen(nb)) && !aux.prec)
	{
		if (aux.space || aux.plus || nb < 0)
		{
			nb = int_put_sign(aux, nb);
			g_size++;
		}
		pt = p_convert(nb, 10);
		ft_putstr(pt);
		g_size += ft_strlen(pt);
	}
	else
		p_handle_int(nb, aux);
}

void	handle_unsg(va_list *args, t_arg aux)
{
	char				fill;
	long long unsigned	x;
	char				*ptr;

	if (aux.l || aux.ll || aux.z)
		x = get_ul_number(args, aux);
	else
		x = get_us_number(args, aux);
	if (aux.pad_zero && !aux.align)
		fill = '0';
	else
		fill = ' ';
	if (aux.nb <= ft_nbrlen(x) && !aux.prec)
	{
		ptr = p_convert(x, 10);
		ft_putstr(ptr);
		g_size += ft_strlen(ptr);
	}
	else
		p_handle_unsg(x, aux, fill);
}

void	handle_char(va_list *args, t_arg aux)
{
	int			i;
	char		c;

	c = va_arg(*args, int);
	i = -1;
	if (aux.nb <= 1)
	{
		ft_putchar(c);
		g_size++;
	}
	else
	{
		if (aux.align)
			ft_putchar(c);
		while (++i < aux.nb - 1)
			ft_putchar(' ');
		if (!aux.align)
			ft_putchar(c);
		g_size += aux.nb;
	}
}

void	handle_str(va_list *args, t_arg aux)
{
	char *p;

	p = va_arg(*args, char*);
	if (p)
	{
		if (aux.nb <= (int)ft_strlen(p))
		{
			ft_putstr(p);
			g_size += ft_strlen(p);
		}
		else
			p_handle_str(p, aux);
	}
	else if (p == NULL)
	{
		ft_putstr("(null)");
		g_size += 6;
	}
}

void	p_handle_str(char *p, t_arg aux)
{
	int	i;

	i = 0;
	if (aux.align)
		ft_putstr(p);
	while (i < (int)(aux.nb - ft_strlen(p)))
	{
		ft_putchar(' ');
		g_size++;
		i++;
	}
	if (!aux.align)
		ft_putstr(p);
	g_size += ft_strlen(p);
}
