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

int	ft_printf(const char *format, ...)
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
			++s_parser.count;
		}
	}
	va_end(ap);
	return (s_parser.count);
}
