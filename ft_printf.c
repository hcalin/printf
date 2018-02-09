/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:29:58 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 14:55:01 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_size;

int		in_print(char *format, va_list *args)
{
	char *ptr;
	char *aux;

	aux = format;
	while (*format)
	{
		ptr = ft_strchr(format, '%');
		if (!ptr)
		{
			ft_putstr(format);
			g_size += ft_strlen(format);
			return (0);
		}
		else
			print_handle(&format, ptr, args);
		if (*format && *format != '%')
		{
			ft_putchar(*format);
			format++;
			g_size++;
		}
	}
	return (0);
}

void	print_handle(char **format, char *ptr, va_list *args)
{
	g_size += (ptr - *format);
	ft_putnstr(*format, ptr - *format);
	if (*(ptr + 1) == '%')
	{
		ft_putstr("%");
		g_size++;
		*format = ptr + 2;
	}
	else
	{
		*format = ptr;
		handle_format(&(*format), args);
	}
}

int		ft_printf(char *format, ...)
{
	va_list	args;

	g_size = 0;
	va_start(args, format);
	in_print(format, &args);
	va_end(args);
	return (g_size);
}
