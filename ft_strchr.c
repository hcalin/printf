/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:34:33 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/06 19:00:25 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
		{
			ptr = (char*)&(s[i]);
			return (ptr);
		}
		i++;
	}
	return (0);
}
