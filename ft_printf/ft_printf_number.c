/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:15:37 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/11 10:04:32 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;
	int	ret;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ret = ft_putchar('-');
		if (ret == -1)
			return (-1);
		len += ret;
		n = -n;
	}
	if (n >= 10)
	{
		ret = ft_putnbr(n / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = ft_putchar((n % 10) + '0');
	if (ret == -1)
		return (-1);
	return (len + ret);
}

int	ft_putunsigned(unsigned int n)
{
	int	len;
	int	ret;

	len = 0;
	if (n >= 10)
	{
		ret = ft_putunsigned(n / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = ft_putchar((n % 10) + '0');
	if (ret == -1)
		return (-1);
	return (len + ret);
}
