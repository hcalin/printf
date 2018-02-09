/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:22:23 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 15:14:57 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				p_put_sign(t_arg *aux)
{
	if (aux->plus)
	{
		g_size++;
		ft_putchar('+');
	}
	else if (aux->space)
	{
		g_size++;
		ft_putchar(' ');
	}
}

unsigned long long	get_ul_number(va_list *args, t_arg aux)
{
	unsigned long int		a;
	unsigned long long int	b;
	size_t					c;

	if (aux.l)
	{
		a = va_arg(*args, unsigned long int);
		return (a);
	}
	else if (aux.ll)
	{
		b = va_arg(*args, unsigned long long int);
		return (b);
	}
	c = va_arg(*args, unsigned long long int);
	return (c);
}

unsigned long long	get_us_number(va_list *args, t_arg aux)
{
	unsigned char	a;
	unsigned short	b;
	unsigned int	c;

	if (aux.ss)
	{
		a = va_arg(*args, unsigned int);
		return (a);
	}
	else if (aux.s)
	{
		b = va_arg(*args, unsigned int);
		return (b);
	}
	else
	{
		c = va_arg(*args, unsigned int);
		return (c);
	}
}

void				set_fill(char *fill, t_arg aux)
{
	if (aux.pad_zero && !aux.align)
		*fill = '0';
	else
		*fill = ' ';
}

char				*p_convert(long long unsigned num, int base)
{
	static char		hex[] = "0123456789abcdef";
	char			*ptr;
	char			*buffer;

	buffer = (char*)malloc(51);
	ptr = &buffer[49];
	*ptr = '\0';
	*--ptr = hex[num % base];
	num /= base;
	while (num != 0)
	{
		*--ptr = hex[num % base];
		num /= base;
	}
	return (ptr);
}
