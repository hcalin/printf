/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:25:38 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 14:27:21 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int		int_put_sign(t_arg aux, long long int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	else if (aux.plus)
		ft_putchar('+');
	else
		ft_putchar(' ');
	return (nb);
}

long long int		get_number_h(va_list *args, t_arg aux)
{
	char	a;
	short	b;
	int		c;

	if (aux.ss)
	{
		a = va_arg(*args, int);
		return (a);
	}
	else if (aux.s)
	{
		b = va_arg(*args, int);
		return (b);
	}
	else
	{
		c = va_arg(*args, int);
		return (c);
	}
}

long long int		get_number_ll(va_list *args, t_arg aux)
{
	long int		a;
	long long int	b;
	size_t			c;

	if (aux.l)
	{
		a = va_arg(*args, long int);
		return (a);
	}
	else if (aux.ll)
	{
		b = va_arg(*args, long long int);
		return (b);
	}
	c = va_arg(*args, long int);
	return (c);
}

char				*convert(long long unsigned num, int base, int type)
{
	static char	hex2[] = "0123456789abcdef";
	static char	hex[] = "0123456789ABCDEF";
	char		*ptr;
	char		*buffer;

	buffer = (char*)malloc(51);
	ptr = &buffer[49];
	*ptr = '\0';
	if (type == 1)
		*--ptr = hex[num % base];
	else
		*--ptr = hex2[num % base];
	num /= base;
	while (num != 0)
	{
		if (type == 1)
			*--ptr = hex[num % base];
		else
			*--ptr = hex2[num % base];
		num /= base;
	}
	return (ptr);
}

void				set_aux(t_arg *aux)
{
	aux->z = 0;
	aux->s = 0;
	aux->ss = 0;
	aux->l = 0;
	aux->ll = 0;
	aux->x = 0;
	aux->is_sign = 0;
	aux->plus = 0;
	aux->pad_zero = 0;
	aux->space = 0;
	aux->prec = 0;
	aux->align = 0;
	aux->nsize = 0;
	aux->hash = 0;
	aux->nb = 0;
	aux->align = 0;
}
