/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:00:33 by rvinnie           #+#    #+#             */
/*   Updated: 2021/01/08 11:00:36 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h> //delete
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct
{
	int			f_minus;
	int			f_zero;
	int			width;
	int			precision;
	int			count;
	const char	*format;
	char		type;
} t_parser;

typedef struct
{
	int			negative;
	int			len;
	int			prec_zeros;
	int			width_zeros;
} t_nbr;

int			ft_printf(const char *, ...);
t_parser	parser(t_parser s_parser, va_list *ap);
t_parser	check_flags(t_parser s_parser);
t_parser	check_width(t_parser s_parser, va_list *ap);
t_parser	check_precision(t_parser s_parser, va_list *ap);
t_parser	handler(t_parser s_parser, va_list *ap);
t_parser	c_handler(t_parser s_parser, va_list *ap);
t_parser	s_handler(t_parser s_parser, va_list *ap);
void		count_putstr(char *str, int count_print);
void		minus_handler(char *str, int count_to_print, int count_ws, int flag);
t_parser	digit_handler(t_parser s_parser, va_list *ap);
t_parser	hex_handler(t_parser s_parser, va_list *ap);
t_parser	null_handler(t_parser s_parser);
size_t		ft_strlen(const char *s);
t_nbr		precision_checker(t_parser s_parser, t_nbr s_nbr);

#endif
