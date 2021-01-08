/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:00:50 by rvinnie           #+#    #+#             */
/*   Updated: 2021/01/08 11:00:52 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		write_str(t_parser s_parser, int count_ws, char ch)
{
	char	ws_or_zero;

	ws_or_zero = ' ';
	if (s_parser.type == '%' && s_parser.f_zero)
		ws_or_zero = '0';
	if (s_parser.f_minus)
	{
		write(1, &ch, 1);
		while (count_ws--)
			write(1, " ", 1);
	}
	else
	{
		while (count_ws--)
			write(1, &ws_or_zero, 1);
		write(1, &ch, 1);
	}
}

t_parser	c_handler(t_parser s_parser, va_list *ap)
{
	char	ch;
	int		count_to_print;
	int		count_ws;

	if (s_parser.type == '%')
		ch = '%';
	else
		ch = va_arg(*ap, int);
	count_to_print = 1;
	if (s_parser.width <= count_to_print)
	{
		write(1, &ch, 1);
		s_parser.count += 1;
	}
	else
	{
		count_ws = s_parser.width - 1;
		write_str(s_parser, count_ws, ch);
		s_parser.count += s_parser.width;
	}
	return (s_parser);
}
