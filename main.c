#include "ft_printf.h"
#include <limits.h> //UINT_MAX

int main()
{
	// char b = 14;
	// int d = 10000;
	// char *pb = &b;
	// int *pd = &d;	
	int *pn = NULL;

	// printf("%20p\n", pb);
	// printf("%p\n", pd);
	ft_printf("%d\n", ft_printf("%p\n", pn));
	printf("%d\n", printf("%p\n", pn));


	return (0);
}
