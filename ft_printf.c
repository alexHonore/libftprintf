/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:14:37 by eardingh          #+#    #+#             */
/*   Updated: 2022/04/08 17:15:46 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.c"
#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	vl;

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
			}
			if (str[i] == 'd' || str[i] == 'i') /* int */
			{
				counter += ft_putnbr_fd(va_arg(vl, int), 1);
			}
			if (str[i] == 'c') /* char */
			{
				counter += ft_putchar_fd(va_arg(vl, int), 1);
			}
			if (str[i] == 's') /* string */
			{
				counter += ft_putstr_fd(va_arg(vl, char *), 1);
			}
			if (str[i] == 'X') // hexadecimal (base 16) upper format
			{
				counter += ft_hexadecimal_upper(va_arg(vl, int));
			}
			if (str[i] == 'x') // hexadecimal (base 16) lower format
			{
				counter += ft_hexadecimal_lower(va_arg(vl, int));
			}
			if (str[i] == 'u') /* unsigned int */
			{
				counter += ft_putnbr_hexa(va_arg(vl, int), 1);
			}
			if (str[i] == 'p') /* unsigned int */
			{
				counter += ft_address(va_arg(vl, unsigned long));
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

	c = 'a';
	s = "test";
	i = 2147483647;
	d = -2147483648;
	x = 456;
	X = 456;
	p = "bozo";
	unsigned int u = -1;

	ft_printf("*********TEST RESULT*********\n");
	ft_printf("c = %c\ni = %i\nd = %d\ns = %s\nx = %x\nX = %X\np = %p\nu = %u\n%% = %%\n\n", c, i, d, s, x, X, p, u);
	printf("real c = %c\n", c);
	printf("real i = %i\n", i);
	printf("real d = %d\n", d);
	printf("real s = %s\n", s);
	printf("real x = %x\n", x);
	printf("real X = %X\n", X);
	printf("real p = %p\n", p);
	printf("real u = %u\n", u);
	printf("real %% = %%\n\n");
}

//Void *
//remove the  last letter to the final result :)