/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:19:36 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 15:28:04 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_hexa(va_list *args, char c, t_arg aux)
{
	char		*p;
	char		fill;
	int			i;

	i = 0;
	b_handle_hexa(&p, c, &aux, args);
	a_handle_hexa(&aux, &fill);
	if (aux.align || (aux.nb <= (int)(ft_strlen(p) + aux.hash)))
	{
		hexa_putx(aux.hash, aux.pad_zero, aux.ok, aux.x);
		aux.ok = 1;
		if (aux.prec)
			while (++i <= (int)(aux.prec - ft_strlen(p)))
				ft_putchar('0');
		(aux.prec > (int)ft_strlen(p)) ?
			(g_size += aux.prec - ft_strlen(p)) : 0;
		ft_putstr(p);
		hexa_put_space(aux, p);
		g_size += ft_strlen(p) + aux.hash;
	}
	else
		p_handle_hexa(p, fill, aux);
}

void		hexa_put_space(t_arg aux, char *p)
{
	int		i;

	i = 0;
	if (!aux.prec && aux.nb > (int)ft_strlen(p) + aux.hash)
		while (++i <= aux.nb - maxx(aux.prec, ft_strlen(p)) - aux.hash)
		{
			ft_putchar(' ');
			g_size++;
		}
	else if (aux.prec && aux.prec > (int)ft_strlen(p) && aux.nb > aux.prec)
	{
		while (++i <= aux.nb - aux.prec - aux.hash)
		{
			ft_putchar(' ');
			g_size++;
		}
	}
}

void		a_handle_hexa(t_arg *aux, char *fill)
{
	aux->ok = 0;
	(aux->prec != 0) ? (aux->pad_zero = 0) : 0;
	if (aux->pad_zero && !aux->align && !aux->prec)
		*fill = '0';
	else
		*fill = ' ';
	if (aux->pad_zero && aux->hash)
	{
		hexa_putx(2, 0, aux->ok, aux->x);
		aux->ok = 1;
	}
}

void		b_handle_hexa(char **p, char c, t_arg *aux, va_list *args)
{
	long long int	nb;

	if (aux->l || aux->ll || aux->z)
		nb = get_ul_number(args, *aux);
	else
		nb = get_us_number(args, *aux);
	if (c == 'x')
		*p = convert(nb, 16, 2);
	else
	{
		aux->x = 1;
		*p = convert(nb, 16, 1);
	}
}

void		p_handle_hexa(char *p, char fill, t_arg aux)
{
	int	i;

	i = 0;
	(aux.prec < (int)ft_strlen(p)) ? (aux.prec = (int)ft_strlen(p)) : 0;
	if (aux.nb > aux.prec + aux.hash)
	{
		while (++i <= aux.nb - aux.prec - aux.hash)
			ft_putchar(fill);
		g_size += aux.nb - aux.prec - aux.hash;
	}
	if (!aux.align)
	{
		hexa_putx(aux.hash, aux.pad_zero, aux.ok, aux.x);
		if (aux.nb > (int)(ft_strlen(p) + aux.hash))
			if (aux.prec)
				x_put_zero(aux, p);
	}
	g_size += ft_strlen(p) + aux.hash;
}
