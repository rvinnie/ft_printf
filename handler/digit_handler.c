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
	if (s_parser.width > s_nbr.prec_zeros + s_nbr.len && s_parser.f_zero)
	{
		s_nbr.width_zeros = s_parser.width - (s_nbr.prec_zeros + s_nbr.len);
		s_nbr.prec_zeros = 0;
	}
	else
		s_nbr.width_zeros = 0;
	return (s_nbr);
}

void	ft_putnbr(long int num)
{
	char a;

	if (num > 9)
		ft_putnbr(num / 10);
	a = num % 10 + 48;
	write(1, &a, 1);
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
	ft_putnbr(nbr);
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