/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:18:08 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 14:21:57 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_handle_unsg(long long unsigned int nb, t_arg aux, char fill)
{
	int		i;
	char	*ptr;

	i = -1;
	ptr = p_convert(nb, 10);
	if (aux.align)
		unsg_align_left(nb, aux, fill);
	else
	{
		if (aux.prec > ft_nbrlen(nb))
			unsg_prec_align_right(aux, nb);
		else
			unsg_align_right(nb, aux, fill);
	}
}

void	unsg_align_right(unsigned long long int nb, t_arg aux, char fill)
{
	char	*ptr;
	int		i;

	i = -1;
	while (++i < (aux.nb - ft_nbrlen(nb)))
	{
		ft_putchar(fill);
		g_size++;
	}
	ptr = p_convert(nb, 10);
	g_size += ft_strlen(ptr);
	ft_putstr(ptr);
}

void	unsg_prec_align_right(t_arg aux, long long unsigned nb)
{
	int		i;
	char	*ptr;

	i = -1;
	while (++i < aux.nb - aux.prec)
	{
		g_size++;
		ft_putchar(' ');
	}
	i = -1;
	while (++i < aux.prec - ft_nbrlen(nb))
	{
		ft_putchar('0');
		g_size++;
	}
	ptr = p_convert(nb, 10);
	g_size += ft_nbrlen(nb);
	ft_putstr(ptr);
}

void	unsg_align_left(long long unsigned nb, t_arg aux, char fill)
{
	int		i;
	char	*ptr;

	i = -1;
	if (aux.prec)
		unsg_prec_align_left(&aux, nb);
	else
	{
		ptr = p_convert(nb, 10);
		ft_putstr(ptr);
		g_size += ft_strlen(ptr);
		while (++i < (int)(aux.nb - ft_strlen(ptr)))
		{
			ft_putchar(fill);
			g_size++;
		}
	}
}

void	unsg_prec_align_left(t_arg *aux, long long unsigned nb)
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
	unsg_align_left(nb, *aux, ' ');
}
