/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:39:31 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/14 18:21:38 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convertcheck(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(*ap, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(*ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthex(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putptr(va_arg(*ap, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	int		ret;
	va_list	ap;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret = convertcheck(format[i], &ap);
		}
		else
			ret = ft_putchar(format[i]);
		if (ret == -1)
			return (va_end(ap), -1);
		len = len + ret;
		i++;
	}
	return (va_end(ap), len);
}
