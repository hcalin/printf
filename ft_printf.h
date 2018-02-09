/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:33:09 by chrihorc          #+#    #+#             */
/*   Updated: 2017/05/04 15:15:20 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_arg
{
	char	*flag;
	int		z;
	int		l;
	int		ll;
	int		s;
	int		ss;
	int		x;
	int		ok;
	int		is_sign;
	int		space;
	int		hash;
	int		plus;
	int		pad_zero;
	int		nsize;
	int		prec;
	char	*number;
	int		nb;
	int		align;
}					t_arg;

int					ft_printf(char *format, ...);
int					maxx(int a, int b);
void				handle_error(void);
void				handle_format(char **format, va_list *args);
void				search_sxpu(char **format, char *ptr,
								t_arg aux, va_list *args);
void				handle_int(va_list *args, t_arg aux);
void				p_handle_int(long long int nb, t_arg aux);
void				print_handle(char **format, char *ptr, va_list *args);
void				int_align_left(long long int nb, t_arg aux, char fill);
void				int_align_right(long long int nb, t_arg aux, char fill);
void				int_prec_align_left(t_arg *aux, long long int nb);
void				int_prec_align_right(t_arg aux, long long int nb);
long long int		int_put_sign(t_arg aux, long long int nb);
long long int		get_number_h(va_list *args, t_arg aux);
long long int		get_number_ll(va_list *args, t_arg aux);
unsigned long long	get_ul_number(va_list *args, t_arg aux);
unsigned long long	get_us_number(va_list *args, t_arg aux);
void				handle_char(va_list *args, t_arg aux);
void				handle_str(va_list *args, t_arg aux);
void				p_handle_str(char *p, t_arg aux);
void				handle_hexa(va_list *args, char c, t_arg aux);
void				a_handle_hexa(t_arg *aux, char *fill);
void				b_handle_hexa(char **p, char c, t_arg *aux, va_list *args);
void				p_handle_hexa(char *p, char fill, t_arg aux);
void				hexa_putx(int hash, int zero, int ok, int x);
void				hexa_put_space(t_arg aux, char *p);
void				handle_ptr(va_list *args, t_arg aux);
void				ext_handle_ptr(void *p, t_arg aux);
void				ext2_handle_ptr(char *p, t_arg aux);
void				ext3_handle_ptr(char *p, t_arg aux);
void				x_put_zero(t_arg aux, char *p);
void				p_handle_ptr(char *p, t_arg aux);
void				p_put_sign(t_arg *aux);
void				handle_unsg(va_list *args, t_arg aux);
void				p_handle_unsg(long long unsigned int x,
								t_arg aux, char fill);
void				unsg_align_right(unsigned long long int nb,
										t_arg aux, char fill);
void				unsg_prec_align_right(t_arg aux, long long unsigned nb);
void				unsg_align_left(long long unsigned nb,
										t_arg aux, char fill);
void				unsg_prec_align_left(t_arg *aux, long long unsigned nb);
void				handle_octa(va_list *args, t_arg aux);
unsigned long long	ext_handle_octa(t_arg *aux, unsigned long long nb,
												va_list *args);
void				ext2_handle_octa(char *p, t_arg aux);
void				check_arg(char c, int *first_zero, t_arg *aux);
void				set_fill(char *fill, t_arg aux);
void				set_aux(t_arg *aux);
void				set_arg(char **format, t_arg *aux, size_t size);
void				set_number(char *format, t_arg *aux);
void				set_prec(char *format, t_arg *aux);
void				a_set_prec(t_arg *aux, int *i, char *c, char **format);
void				a_set_width(t_arg *aux, int *i, char *c, char **format);
void				set_flags(char *ptr, t_arg *aux);
char				*convert(long long unsigned int num, int base, int type);
char				*p_convert(long long unsigned num, int base);
extern int			g_size;
static const char	g_flags[] = "sSpdDioOuUxXcC";
#endif
