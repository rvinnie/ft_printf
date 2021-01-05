#include "ft_printf.h"
#include <limits.h>

int main()
{
	// printf("%u\n", UINT_MAX);        ///UINT_MAX
	ft_printf("%x\n", 100);
	// printf("%ld\n", 4294967295); 
	return (0);
}


// int	hexlen(int num)
// {
// 	int len;

// 	if (num == 0)
// 		len = 1;
// 	while (num)
// 	{
// 		num /= 16;
// 		len++;
// 	}
// 	return (len);
// }

// void to_hex(int num, char arr[])
// {
// 	int d;

// 	if (!num)
// 		return;
// 	to_hex(num / 16, arr);
// 	d = arr[num % 16];
// 	write(1, &d, 1);
// }

// int main()
// {
	
// 	char lower[] = "0123456789abcdef";
// 	char upper[] = "0123456789ABCDEF";
// 	int num = 15;
// 	printf("%d\n", hexlen(num));
// 	to_hex(num, upper);
// 	// printf("%020.10x\n", 1000);
//     return 0;
// }