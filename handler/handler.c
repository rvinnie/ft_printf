#include "../ft_printf.h"

t_parser handler(t_parser s_parser, va_list *ap)
{
	if (s_parser.type == 'c' || s_parser.type == '%')
		s_parser = c_handler(s_parser, ap);
	else if (s_parser.type == 's')
		s_parser = s_handler(s_parser, ap);
	else if (s_parser.type == 'i' || s_parser.type == 'd' || s_parser.type == 'u')
		s_parser = digit_handler(s_parser, ap);
	else if (s_parser.type == 'x' || s_parser.type == 'X')  // || s_parser.type == 'p'
		s_parser = hex_handler(s_parser, ap);
	return (s_parser);
}