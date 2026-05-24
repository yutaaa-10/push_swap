/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_Hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:05:02 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/13 21:02:26 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char *base)
{
	int	len;
	int	ret;

	len = 0;
	if (n >= 16)
	{
		ret = ft_puthex(n / 16, base);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = ft_putchar(base[n % 16]);
	if (ret == -1)
		return (-1);
	return (len + ret);
}

static int	ft_puthex_long(unsigned long n, char *base)
{
	int	len;
	int	ret;

	len = 0;
	if (n >= 16)
	{
		ret = ft_puthex_long(n / 16, base);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = ft_putchar(base[n % 16]);
	if (ret == -1)
		return (-1);
	return (len + ret);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	ret;

	if (!ptr)
		return (ft_putstr("(nil)"));
	ret = ft_putstr("0x");
	if (ret == -1)
		return (-1);
	len = ret;
	ret = ft_puthex_long((unsigned long)ptr, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	return (len + ret);
}
