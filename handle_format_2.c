/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:56:23 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 15:25:43 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_arg(char **format, t_arg *aux, size_t size)
{
	char	*c;
	int		first_zero;
	int		i;

	first_zero = 0;
	i = -1;
	c = *format;
	while (++i < (int)size)
	{
		check_arg(c[i], &first_zero, aux);
		if (ft_isdigit(c[i]) && c[i] != '0')
		{
			if (i > 0 && c[i - 1] == '.')
				a_set_prec(aux, &i, c, format);
			else
			{
				first_zero = 1;
				a_set_width(aux, &i, c, format);
			}
		}
	}
}

void	a_set_width(t_arg *aux, int *i, char *c, char **format)
{
	int	start;

	aux->nsize = 0;
	start = *i;
	while (ft_isdigit(c[*i]))
	{
		aux->nsize++;
		(*i)++;
	}
	set_number((*format) + start, aux);
}

void	a_set_prec(t_arg *aux, int *i, char *c, char **format)
{
	int	start;

	aux->pad_zero = 0;
	aux->nsize = 0;
	start = *i;
	while (ft_isdigit(c[(*i)]))
	{
		aux->nsize++;
		(*i)++;
	}
	set_prec((*format) + start, aux);
}

void	set_number(char *format, t_arg *aux)
{
	char	*number;

	number = (char*)malloc(aux->nsize + 2);
	ft_strncpy(number, format, aux->nsize);
	aux->nb = ft_atoi(number);
}

void	set_prec(char *format, t_arg *aux)
{
	char	*number;

	number = (char*)malloc(aux->nsize + 2);
	ft_strncpy(number, format, aux->nsize);
	aux->prec = ft_atoi(number);
}
