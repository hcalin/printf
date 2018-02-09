/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:03:42 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 15:09:17 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_arg(char c, int *first_zero, t_arg *aux)
{
	if (c == '-')
		aux->align = 1;
	if (c == '+')
		aux->plus = 1;
	if (c == ' ')
		aux->space = 1;
	if (c == '#')
		aux->hash = 2;
	if (c == '0' && !*first_zero)
	{
		*first_zero = 1;
		aux->pad_zero = 1;
	}
}
