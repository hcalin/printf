/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:59:53 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/09 19:00:06 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_whitespace(char str)
{
	if (str == ' ' || str == '\t' || str == '\n' ||
			str == '\r' || str == '\v' || str == '\f')
		return (1);
	return (0);
}

int			ft_atoi(char *str)
{
	int num;
	int i;
	int	sign;

	if (!str)
		return (0);
	sign = 1;
	num = 0;
	i = 0;
	while (str[i] && ft_whitespace(str[i]))
		i++;
	if (str[i] == '-' && !(str[i - 1] == '+'))
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+' && !(str[i - 1] == '-'))
		i++;
	while (str[i] && ft_digit(str[i]))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (sign * num);
}
