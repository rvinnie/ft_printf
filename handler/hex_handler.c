#include "../ft_printf.h"

int			hexlen(unsigned int num)
{
	int len;

	if (num == 0)
		len = 1;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

void		to_hex(unsigned int num, char *arr, int flag)
{
	int d;

	if (flag == 0 && num == 0)
		write(1, "0", 1);
	if (!num) return;
	to_hex(num / 16, arr, 1);
	d = arr[num % 16];
	write(1, &d, 1);
}

t_parser	create_hex_str(t_parser s_parser, t_nbr s_nbr, unsigned int nbr)
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
	while (zero_count--)
		write(1, "0", 1);
	if (s_parser.type == 'x')
		to_hex(nbr, "0123456789abcdef", 0);
	else
		to_hex(nbr, "0123456789ABCDEF", 0);
	if (s_parser.f_minus)
	{
		while (ws_count--)
			write(1, " ", 1);
	}
	return (s_parser);
}

t_parser	hex_handler(t_parser s_parser, va_list *ap)
{
	t_nbr		s_nbr;
	long int	nbr;

	s_nbr.negative = 0;
	nbr = va_arg(*ap, unsigned int);
	s_nbr.len = hexlen(nbr);
	s_nbr = precision_checker(s_parser, s_nbr);
	s_parser = create_hex_str(s_parser, s_nbr, nbr);
	return (s_parser);
}