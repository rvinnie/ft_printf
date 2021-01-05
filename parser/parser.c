#include "../ft_printf.h"

t_parser	check_flags(t_parser s_parser)
{
	s_parser.f_minus = 0;
	s_parser.f_zero = 0;
	while (*s_parser.format == '-' || *s_parser.format == '0')
	{
		if (*s_parser.format == '-')
			s_parser.f_minus = 1;
		else if (*s_parser.format == '0')
			s_parser.f_zero = 1;
		s_parser.format++;
	}
	if (s_parser.f_minus == 1 && s_parser.f_zero == 1)
		s_parser.f_zero = 0;
	return (s_parser);
}

t_parser	check_width(t_parser s_parser, va_list *ap)
{
	s_parser.width = 0;
	if (*s_parser.format == '*')
	{
		s_parser.width = va_arg(*ap, int);
		s_parser.format++;
	}
	else
	{
		while (*s_parser.format >= 48 && *s_parser.format <= 57)
			s_parser.width = s_parser.width * 10 + (*s_parser.format++ - '0');
	}
	return (s_parser);
}

t_parser	check_precision(t_parser s_parser, va_list *ap)
{
	s_parser.precision = -1;
	if (*s_parser.format == '.')
	{
		s_parser.format++;
		s_parser.precision = 0;
		if (*s_parser.format == '*')
		{
			s_parser.precision = va_arg(*ap, int);
			s_parser.format++;
		}
		else
		{
			while (*s_parser.format >= 48 && *s_parser.format <= 57 && s_parser.precision > -1)
				s_parser.precision = s_parser.precision * 10 + (*s_parser.format++ - '0');
		}
	}
	return (s_parser);
}

t_parser	check_types(t_parser s_parser)
{
	char	ch;

	ch = *s_parser.format;
	s_parser.type = '!';
	if (ch == 'c' || ch == 's' || ch == 'p' ||
		ch == 'd' || ch == 'i' || ch == 'u' ||
		ch == 'x' || ch == 'X' || ch == '%')
		s_parser.type = ch;
	s_parser.format++;
	return (s_parser);
}

t_parser	parser(t_parser s_parser, va_list *ap)
{
	s_parser = check_flags(s_parser);
	s_parser = check_width(s_parser, ap);
	s_parser = check_precision(s_parser, ap);
	s_parser = check_types(s_parser);
	return (s_parser);
}