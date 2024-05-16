#include <stdarg.h>
#include <unistd.h>

void print_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len+=write(1, str++, 1);
}

void print_num(long long int num, int base, int *len)
{
	char *hexa = "0123456789abcdef";

	if (num < 0)
	{
		num = -num;
		*len+=write(1, "-", 1);
	}
	if (num >= base)
		print_num((num / base), base, len);
	*len+=write(1, &hexa[num % base], 1);
}

int ft_printf(const char *format, ... )
{
	int len = 0;
	va_list ptr;

	va_start(ptr, format);
	while(*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				print_str(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				print_num((long long int)va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				print_num((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len+=write(1, format, 1);
		format++;
	}
	return (va_end(ptr), len);
}

/*#include <stdio.h>

int main()
{
    int len;

    ft_printf("%s\n", "toto");
    printf("%s\n", "toto");

    ft_printf("Number: %d\n", -2147483648);
    printf("Number: %ld\n", -2147483648);

    ft_printf("Hexadecimal: %x\n", 42);
    printf("Hexadecimal: %x\n", 42);

    return (0);
}*/
