/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:09:53 by anshimiy          #+#    #+#             */
/*   Updated: 2022/04/11 16:37:43 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.c"
#include "libftprintf.h"

int	ft_is_flag(const char c)
{
	if(c == '-')
		return (1);
	else if (c == '+')
	{
		return (2);
	}
	else if (c == '#')
		return (3);
	else if (c == '0')
		return (4);
	else if (c == ' ')
		return (4);
	else
		return (0);
}

void	ft_print_string(va_list vl, const char *c)
{
	//todo make one functions for xX sS etc
	if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 'd' || c == 'i') /* int */
		ft_putnbr_fd(va_arg(vl, int), 1);
	else if (c == 'c') /* char */
		ft_putchar_fd(va_arg(vl, int), 1);
	else if (c == 's') /* string */
		ft_putstr_fd(va_arg(vl, char *), 1);
	else if (c == 'X') // hexadecimal (base 16) upper format
		ft_hexadecimal_upper(va_arg(vl, int));
	else if (c == 'x') // hexadecimal (base 16) lower format
		ft_hexadecimal_lower(va_arg(vl, int));
	else if (c == 'u') /* unsigned int */
		ft_putnbr_hexa(va_arg(vl, int), 1);
	else if (c == 'p') /* unsigned int */
		ft_address(va_arg(vl, unsigned long));
}

// %[flags][width][.precision][length]specifier
int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		vl;

	va_start(vl, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_print_string();
		}
		else
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
	printf("\n------------------\n");
	printf("printf i = %i\n", i);
	ft_printf("ft_printf i = %i\n", i);
	printf("\n------------------\n");
	printf("printf d = %d\n", d);
	ft_printf("ft_printf d = %d\n", d);
	printf("\n------------------\n");
	printf("printf s = %s\n", s);
	ft_printf("ft_printf s = %s\n", s);
	printf("\n------------------\n");
	printf("printf x = %x\n", x);
	ft_printf("ft_printf x = %x\n", x);
	printf("\n------------------\n");
	printf("printf X = %X\n", X);
	ft_printf("ft_printf X = %X\n", X);
	printf("\n------------------\n");
	printf("printf p = %p\n", p);
	ft_printf("ft_printf p = %p\n", p);
	printf("\n------------------\n");
	printf("printf u = %u\n", u);
	ft_printf("ft_printf u = %u\n", u);
	printf("\n------------------\n");
	printf("printf %% = %%\n");
	ft_printf("ft_printf %% = %%\n");
	printf("\n------------------\n");
	printf("printf d->%d  c->%c  ->%s\n", 10, 'A', "Hello");
	ft_printf("ft_printf d->%d  c->%c  ->%s\n", 10, 'A', "Hello");
}
