/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:00:11 by rvinnie           #+#    #+#             */
/*   Updated: 2021/01/08 11:00:15 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

int ft_printf(const char *format, ...)
{
	va_list		ap;
	t_parser	s_parser;

	s_parser.count = 0;
	va_start(ap, format);
	s_parser.format = format;
	while (*s_parser.format)
	{
		if (*s_parser.format == '%')
		{
			s_parser.format++;
			s_parser = parser(s_parser, &ap);
			s_parser = handler(s_parser, &ap);
		}
		else
		{
			write(1, s_parser.format++, 1);
			// s_parser.format++;
			++s_parser.count;
		}
	}
	// printf("%-12s %d\n", "f_minus:", s_parser.f_minus);
	// printf("%-12s %d\n", "f_zero:", s_parser.f_zero);
	// printf("%-12s %d\n", "width:",s_parser.width);
	// printf("%-12s %d\n", "precision:", s_parser.precision);
	// printf("%-12s %c\n", "type:", s_parser.type);
	va_end(ap);
	return (s_parser.count);
}
