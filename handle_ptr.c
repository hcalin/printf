/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:15:54 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 15:18:37 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_ptr(va_list *args, t_arg aux)
{
	int			i;
	void		*p;

	p = va_arg(*args, long long unsigned*);
	if (!p)
	{
		i = -1;
		if (!aux.align && aux.nb > 5)
		{
			while (++i < aux.nb - 5)
				ft_putchar(' ');
			g_size += aux.nb - 5;
		}
		ft_putstr("(nil)");
		g_size += 5;
		if (aux.align && aux.nb > 5)
		{
			while (++i < aux.nb - 5)
				ft_putchar(' ');
			g_size += aux.nb - 5;
		}
	}
	else
		ext_handle_ptr(p, aux);
}

void	ext_handle_ptr(void *p, t_arg aux)
{
	char	*ptr;

	(aux.space) ? (aux.ok = 1) : 0;
	(aux.plus) ? (aux.ok = 1) : 0;
	ptr = p_convert((long long unsigned)p, 16);
	if (aux.nb <= (int)ft_strlen(ptr) + 2 && !aux.prec)
	{
		p_put_sign(&aux);
		ft_putstr("0x");
		ft_putstr(ptr);
		g_size += ft_strlen(ptr) + 2;
	}
	else
		p_handle_ptr(ptr, aux);
}

void	p_handle_ptr(char *p, t_arg aux)
{
	int		i;
	char	fill;

	if (aux.pad_zero && !aux.align)
		fill = '0';
	else
		fill = ' ';
	if (aux.align)
		aux.pad_zero = 0;
	ext2_handle_ptr(p, aux);
	i = -1;
	if (!aux.prec)
		while (++i < (int)(aux.nb - ft_strlen(p) - 2 - aux.ok))
		{
			ft_putchar(fill);
			g_size++;
		}
	else
		while (++i < (int)(aux.nb - aux.prec - 2 - aux.ok))
		{
			ft_putchar(fill);
			g_size++;
		}
	ext3_handle_ptr(p, aux);
	g_size += ft_strlen(p) + 2;
}

void	ext2_handle_ptr(char *p, t_arg aux)
{
	int	i;

	i = -1;
	if (aux.align || aux.pad_zero)
	{
		p_put_sign(&aux);
		ft_putstr("0x");
		if (!aux.pad_zero || aux.nb <= (int)ft_strlen(p) || aux.align)
		{
			if (aux.prec > (int)ft_strlen(p))
			{
				while (++i < (int)(aux.prec - ft_strlen(p)))
					ft_putchar('0');
				g_size += aux.prec - ft_strlen(p);
			}
			ft_putstr(p);
		}
	}
	if ((aux.plus || aux.space) && (int)ft_strlen(p) < aux.nb)
		aux.nb--;
}

void	ext3_handle_ptr(char *p, t_arg aux)
{
	int	i;

	if (!aux.align)
	{
		if (!aux.pad_zero)
		{
			p_put_sign(&aux);
			ft_putstr("0x");
		}
		if (aux.prec > (int)ft_strlen(p))
		{
			i = -1;
			while (++i < (int)(aux.prec - ft_strlen(p)))
				ft_putchar('0');
			g_size += aux.prec - ft_strlen(p);
		}
		ft_putstr(p);
	}
}
