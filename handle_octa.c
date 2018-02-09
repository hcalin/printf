/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:01:08 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 15:29:01 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				handle_octa(va_list *args, t_arg aux)
{
	char				*p;
	unsigned long long	nb;
	char				fill;

	nb = 0;
	(aux.hash == 2) ? (aux.hash = 1) : 0;
	(aux.prec != 0) ? (aux.hash = 0) : 0;
	set_fill(&fill, aux);
	nb = ext_handle_octa(&aux, nb, args);
	p = p_convert(nb, 8);
	aux.x = 0;
	if (!aux.prec || aux.prec <= (int)ft_strlen(p))
		while (++aux.x <= (int)(aux.nb - (int)ft_strlen(p) - aux.hash))
		{
			ft_putchar(fill);
			g_size++;
		}
	else if (aux.nb > aux.prec)
		while (++aux.x <= (int)(aux.nb - aux.prec - aux.hash))
		{
			ft_putchar(fill);
			g_size++;
		}
	ext2_handle_octa(p, aux);
	g_size += ft_strlen(p);
}

unsigned long long	ext_handle_octa(t_arg *aux,
					unsigned long long nb, va_list *args)
{
	char	*p;

	if (aux->l || aux->ll || aux->z)
		nb = get_ul_number(args, *aux);
	else
		nb = get_us_number(args, *aux);
	aux->x = 0;
	p = p_convert(nb, 8);
	if (aux->nb <= (int)ft_strlen(p) || aux->align)
	{
		if (aux->hash && !aux->prec)
		{
			ft_putchar('0');
			g_size++;
		}
		aux->align = 1;
		if (aux->prec && aux->prec > (int)ft_strlen(p))
		{
			while (++aux->x <= (int)(aux->prec - ft_strlen(p)))
				ft_putchar('0');
			g_size += aux->prec - ft_strlen(p);
		}
		ft_putstr(p);
	}
	return (nb);
}

void				ext2_handle_octa(char *p, t_arg aux)
{
	int	i;

	if (!aux.align)
	{
		if (!aux.pad_zero && aux.hash && !aux.prec)
		{
			ft_putchar('0');
			g_size++;
		}
		if (aux.prec)
		{
			i = 0;
			while (++i <= (int)(aux.prec - ft_strlen(p)))
				ft_putchar('0');
			g_size += aux.prec - ft_strlen(p);
		}
		ft_putstr(p);
	}
}
