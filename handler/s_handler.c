#include "../ft_printf.h"

void		count_putstr(char *str, int count_print)
{
	while (count_print--)
		write(1, str++, 1);
}

void		print_ws(int count_ws)
{
	while (count_ws--)
		write(1, " ", 1);
}

void		minus_handler(char *str, int count_to_print, int count_ws, int flag)
{
	if (flag)
	{
		count_putstr(str, count_to_print);
		print_ws(count_ws);
	}
	else 
	{
		print_ws(count_ws);
		count_putstr(str, count_to_print);
	}
}

t_parser	s_handler(t_parser s_parser, va_list *ap)
{
	char	*str;
	int		count_to_print;
	int		count_ws;

	str = va_arg(*ap, char *);
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