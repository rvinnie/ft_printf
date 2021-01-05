#include "ft_printf.h"
#include <limits.h> //UINT_MAX

int main()
{
	ft_printf("%d\n", ft_printf("%x\n", UINT_MAX));
	printf("%d\n", printf("%x\n", UINT_MAX));
	return (0);
}
