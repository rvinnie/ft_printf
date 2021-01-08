/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:01:01 by rvinnie           #+#    #+#             */
/*   Updated: 2021/01/08 11:01:02 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			nbrlen(long int n)
{
	int	len;

	if (n == 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

t_nbr		precision_checker(t_parser s_parser, t_nbr s_nbr)
{
	if (s_parser.precision > s_nbr.len)
		s_nbr.prec_zeros = s_parser.precision - s_nbr.len;
	else
		s_nbr.prec_zeros = 0;
	//if (s_parser.width > s_nbr.prec_zeros + s_nbr.len)
	//{
	//	s_nbr.width_zeros = s_parser.width - (s_nbr.prec_zeros + s_nbr.len);
	//	s_nbr.prec_zeros = 0;
	//}
	if (s_nbr.prec_zeros < 1 && s_parser.width > s_nbr.len && s_parser.f_zero)
		s_nbr.width_zeros = s_parser.width - s_nbr.len;
	else
		s_nbr.width_zeros = 0;
	if (s_parser.precision <= s_nbr.len && s_parser.precision != -1)
		s_nbr.width_zeros = 0;
	//printf("%d %d %d\n", s_nbr.prec_zeros, s_nbr.len, s_nbr.width_zeros);
	return (s_nbr);
}

t_parser	ft_putnbr(t_parser s_parser, long int num)
{
	char a;

	if (s_parser.precision == 0 && num == 0)
	{
		if (s_parser.width != 0)
			write(1, " ", 1);
		else
			s_parser.count--;
		return (s_parser);
	}
	if (num > 9)
		ft_putnbr(s_parser, num / 10);
	a = num % 10 + 48;
	write(1, &a, 1);
	return (s_parser);
}

t_parser	create_str(t_parser s_parser, t_nbr s_nbr, long int nbr)
{
	int	zero_count;
	int	ws_count;

	zero_count = s_nbr.prec_zeros > s_nbr.width_zeros ? s_nbr.prec_zeros : s_nbr.width_zeros;
	ws_count = s_parser.width - (s_nbr.len + zero_count);
	if (ws_count < 0)
		ws_count = 0;
	s_parser.count += ws_count + s_nbr.len + s_nbr.negative + zero_count;
	if (s_parser.f_minus == 0)
	{
		while (ws_count--)
			write(1, " ", 1);
	}
	if (s_nbr.negative)
		write(1, "-", 1);
	while (zero_count--)
		write(1, "0", 1);
	s_parser = ft_putnbr(s_parser, nbr);
	if (s_parser.f_minus)
	{
		while (ws_count--)
			write(1, " ", 1);
	}
	return (s_parser);
}

t_parser	digit_handler(t_parser s_parser, va_list *ap)
{
	t_nbr		s_nbr;
	long int	nbr;

	s_nbr.negative = 0;
	if (s_parser.type == 'u')
		nbr = va_arg(*ap, unsigned int);
	else
		nbr = va_arg(*ap, int);
	if (nbr < 0)
	{
		s_nbr.negative = 1;
		nbr *= -1;
		s_parser.width--;
	}
	s_nbr.len = nbrlen(nbr);
	s_nbr = precision_checker(s_parser, s_nbr);
	s_parser = create_str(s_parser, s_nbr, nbr);
	return (s_parser);
}
