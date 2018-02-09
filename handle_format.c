/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:08:39 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 15:26:06 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_error(void)
{
	ft_putstr("\nError at function call\n");
	exit(EXIT_FAILURE);
}

void	set_flags(char *ptr, t_arg *aux)
{
	if (*(ptr - 1) == 'l' && *(ptr - 2) == 'l')
		aux->ll = 1;
	else if (*(ptr - 1) == 'l')
		aux->l = 1;
	else if (*(ptr - 1) == 'h' && *(ptr - 2) == 'h')
		aux->ss = 1;
	else if (*(ptr - 1) == 'h')
		aux->s = 1;
	else if (*(ptr - 1) == 'z')
		aux->z = 1;
	else if (*(ptr - 1) == 'j')
		aux->l = 1;
}

void	handle_format(char **format, va_list *args)
{
	char		*ptr;
	t_arg		aux;

	set_aux(&aux);
	ptr = *format;
	while (!(aux.flag = ft_strchr(g_flags, *ptr)) && *ptr)
		ptr++;
	if (!*ptr)
		handle_error();
	else
		set_arg(format, &aux, ptr - *format);
	set_flags(ptr, &aux);
	if (ft_strchr("dDi", *(aux.flag)))
	{
		*format = ptr + 1;
		handle_int(args, aux);
	}
	if (ft_strchr("cC", *(aux.flag)))
	{
		*format = ptr + 1;
		handle_char(args, aux);
	}
	search_sxpu(format, ptr, aux, args);
}

void	search_sxpu(char **format, char *ptr,
							t_arg aux, va_list *args)
{
	if (ft_strchr("sS", *(aux.flag)))
	{
		*format = ptr + 1;
		handle_str(args, aux);
	}
	if (ft_strchr("xX", *(aux.flag)))
	{
		*format = ptr + 1;
		handle_hexa(args, *(ft_strchr("xX", *(aux.flag))), aux);
	}
	if ('p' == *(aux.flag))
	{
		*format = ptr + 1;
		handle_ptr(args, aux);
	}
	if (ft_strchr("uU", *(aux.flag)))
	{
		*format = ptr + 1;
		handle_unsg(args, aux);
	}
	if (ft_strchr("oO", *(aux.flag)))
	{
		*format = ptr + 1;
		handle_octa(args, aux);
	}
}
