#include "../ft_printf.h"

t_parser	null_handler(t_parser s_parser)
{
	char	*str;
	int		count_to_print;
	int		count_ws;

	str = "(null)";
	count_to_print = ft_strlen(str);
	if (s_parser.precision != -1 && s_parser.precision < count_to_print)
		count_to_print = s_parser.precision;
	if (s_parser.width <= count_to_print)
	{
		count_putstr(str, count_to_print);
		s_parser.count += count_to_print;
	}
	else
	{
		count_ws = s_parser.width - count_to_print;
		minus_handler(str, count_to_print, count_ws, s_parser.f_minus);
		s_parser.count += s_parser.width;
	}
	return (s_parser);
}

t_parser	handler(t_parser s_parser, va_list *ap)
{
	if (s_parser.type == 'c' || s_parser.type == '%')
		s_parser = c_handler(s_parser, ap);
	else if (s_parser.type == 's')
		s_parser = s_handler(s_parser, ap);
	else if (s_parser.type == 'i' || s_parser.type == 'd' || s_parser.type == 'u')
		s_parser = digit_handler(s_parser, ap);
	else if (s_parser.type == 'x' || s_parser.type == 'X' || s_parser.type == 'p')
		s_parser = hex_handler(s_parser, ap);
	return (s_parser);
}