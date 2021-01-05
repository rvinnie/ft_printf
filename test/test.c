#include <stdio.h>

struct test
{
	int		f_minus;
	int		f_zero;
	int		width;
	int		precision;
	int		length; // Длина строки до типа.
	char	*type;
};

// c s p d i u x X %
// -0.*
// printf возвращает длину напечатанной строки.
// Если наткнулись на звездочку, тогда через &argptr идем и берем элемент, который нам нужен.
// Передаем &argptr в parser.
// отрицательная ширина и точность. Отрицательная точность - 0.
// Для каждый типа своя функция в processer. Одна функция для d,i; одна для x,X.

int main()
{
	int x = 14;
	int *ptr = &x;
	// printf("char - %c\n", 'a');
	// printf("string - %s\n","qwerty");
	// printf("pointer - %p\n", ptr);
	// printf("d - %d\n", 123);
	// printf("int - %i\n", 1435246);
	// printf("unsigned - %u\n", -14);
	// printf("x - %-x\n", 59);
	// printf("X - %X\n", 59);

	printf("------------\nchar\n------------\n");
	printf("|%10.7c|\n", 'a');
	printf("|%-10.7c|\n", 'a');
	printf("|%10.0c|\n", 'a');
	printf("|%-10.0c|\n", 'a');
	
	printf("------------\nint, d\n------------\n");
	printf("|%10.5i|\n", 12345);
	printf("|%-10.5i|\n", 12345);
	printf("|%10.2i|\n", 12345);
	printf("|%-10.2i|\n", 12345);

	printf("------------\nstring\n------------\n");
	printf("|%10.7s|\n", "qwerty");
	printf("|%-10.7s|\n", "qwerty");
	printf("|%10.2s|\n", "qwerty");
	printf("|%-10.2s|\n", "qwerty");

	printf("------------\npointer\n----------------------\n");
	printf("|%20.15p|\n", ptr);
	printf("|%-020.7p|\n", ptr);
	printf("|%20.2p|\n", ptr);
	printf("|%-20.2p|\n", ptr);

	printf("----------------------\nx\n------------\n");
	printf("|%10.7x|\n", 162);
	printf("|%-10.7x|\n", 162);
	printf("|%10.2x|\n", 162);
	printf("|%-10.2x|\n", 162);
	printf("------------\n");
	printf("%d", printf("", "qwerty"));
}