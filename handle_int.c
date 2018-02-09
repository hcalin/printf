/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:57:36 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 15:21:00 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_handle_int(long long int nb, t_arg aux)
{
	int		i;
	char	fill;

	i = -1;
	if (aux.pad_zero && !aux.prec && !aux.align)
		fill = '0';
	else
		fill = ' ';
	if (aux.align)
		int_align_left(nb, aux, fill);
	else
	{
		if (aux.prec > ft_nbrlen(nb))
			int_prec_align_right(aux, nb);
		else
			int_align_right(nb, aux, fill);
	}
}

void	int_align_right(long long int nb, t_arg aux, char fill)
{
	char	*ptr;
	int		i;

	i = -1;
	if (aux.pad_zero && (aux.plus || nb < 0 || aux.space))
	{
		nb = int_put_sign(aux, nb);
		g_size++;
		aux.nb--;
	}
	else if (aux.plus || nb < 0 || aux.space)
		aux.nb--;
	while (++i < (aux.nb - ft_nbrlen(nb)))
	{
		ft_putchar(fill);
		g_size++;
	}
	if (!aux.pad_zero && (aux.plus || nb < 0 || aux.space))
	{
		nb = int_put_sign(aux, nb);
		g_size++;
	}
	ptr = convert(nb, 10, 1);
	g_size += ft_strlen(ptr);
	ft_putstr(ptr);
}

void	int_prec_align_right(t_arg aux, long long int nb)
{
	int		i;
	char	*ptr;

	i = -1;
	if (aux.plus || nb < 0 || aux.space)
		aux.is_sign = 1;
	while (++i < aux.nb - aux.prec - aux.is_sign)
	{
		g_size++;
		ft_putchar(' ');
	}
	if (aux.is_sign)
		nb = int_put_sign(aux, nb);
	i = -1;
	while (++i < aux.prec - ft_nbrlen(nb))
	{
		ft_putchar('0');
		g_size++;
	}
	ptr = convert(nb, 10, 1);
	g_size += ft_nbrlen(nb) + aux.is_sign;
	ft_putstr(ptr);
}

void	int_align_left(long long int nb, t_arg aux, char fill)
{
	int		i;
	char	*ptr;

	i = -1;
	if ((nb < 0 || aux.plus || aux.space) && !aux.is_sign)
	{
		aux.is_sign = 1;
		g_size++;
		nb = int_put_sign(aux, nb);
	}
	if (aux.prec)
		int_prec_align_left(&aux, nb);
	else
	{
		ptr = convert(nb, 10, 1);
		ft_putstr(ptr);
		g_size += ft_strlen(ptr);
		while (++i < (int)(aux.nb - ft_strlen(ptr)) - aux.is_sign)
		{
			ft_putchar(fill);
			g_size++;
		}
	}
}

void	int_prec_align_left(t_arg *aux, long long int nb)
{
	int	i;

	i = aux->prec - ft_nbrlen(nb);
	if (aux->prec > ft_nbrlen(nb))
	{
		while (i--)
		{
			ft_putchar('0');
			g_size++;
			aux->nb--;
		}
	}
	aux->prec = 0;
	int_align_left(nb, *aux, ' ');
}
