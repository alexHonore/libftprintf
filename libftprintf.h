/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:15:27 by eardingh          #+#    #+#             */
/*   Updated: 2022/04/08 12:33:53 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>


int	    ft_printf(const char *, ...);
int     ft_putchar_fd(char c, int fd);
int	    ft_putnbr_fd(int n, int fd);
int	    ft_hexadecimal_upper(int n);
int     ft_putchar_lower(char c, int fd);
int     ft_hexadecimal_lower(int n);
int	    ft_putnbr_hexadecimal(unsigned int n, int fd);
int     ft_putnbr_hexa(unsigned int c, int fd);

#endif
