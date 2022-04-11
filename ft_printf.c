
#include "function.c"
#include "libftprintf.h"

int	ft_is_flag()
{
	
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			counter;
	va_list		vl;

	va_start(vl, str);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
			{
				counter += ft_putchar_fd('%', 1);
				break; 
			}
			if (str[i] == 'd' || str[i] == 'i') /* int */
			{
				counter += ft_putnbr_fd(va_arg(vl, int), 1);
				break;
			}
			if (str[i] == 'c') /* char */
			{
				counter += ft_putchar_fd(va_arg(vl, int), 1);
				break;
			}
			if (str[i] == 's') /* string */
			{
				counter += ft_putstr_fd(va_arg(vl, char *), 1);
				break;
			}
			if (str[i] == 'X') // hexadecimal (base 16) upper format
			{
				counter += ft_hexadecimal_upper(va_arg(vl, int));
				break;
			}
			if (str[i] == 'x') // hexadecimal (base 16) lower format
			{
				counter += ft_hexadecimal_lower(va_arg(vl, int));
				break;
			}
			if (str[i] == 'u') /* unsigned int */
			{
				counter += ft_putnbr_hexa(va_arg(vl, int), 1);
				break;
			}
			if (str[i] == 'p') /* unsigned int */
			{
				counter += ft_address(va_arg(vl, unsigned long));
				break;
			}
		}
		ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(vl);
	return (0);
}

int	main(void)
{
	char	c;
	char	*s;
	int		i;
	int		d;
	int		x;
	int		X;
	char	*p;

	s = "test";
	p = "bozo";
	d = -2147483648;
	i = 2147483647;
	c = 'a';
	x = 456;
	X = 456;
	unsigned int u = -1;

	ft_printf("*********TEST RESULT*********\n");
	printf("printf c = %c\n", c);
	ft_printf("ft_printf c = %c\n", c);
	printf("------------------");
	printf("printf i = %i\n", i);
	ft_printf("ft_printf i = %i\n", i);
	printf("------------------");
	printf("printf d = %d\n", d);
	ft_printf("ft_printf d = %d\n", d);
	printf("------------------");
	printf("printf s = %s\n", s);
	ft_printf("ft_printf s = %s\n", s);
	printf("------------------");
	printf("printf x = %x\n", x);
	ft_printf("ft_printf x = %x\n", x);
	printf("------------------");
	printf("printf X = %X\n", X);
	ft_printf("ft_printf X = %X\n", X);
	printf("------------------");
	printf("printf p = %p\n", p);
	ft_printf("ft_printf p = %p\n", p);
	printf("------------------");
	printf("printf u = %u\n", u);
	ft_printf("ft_printf u = %u\n", u);
	printf("------------------");
	printf("printf %% = %%\n\n");
	ft_printf("ft_printf %% = %%\n\n");
}

//Void *
//remove the  last letter to the final result :)