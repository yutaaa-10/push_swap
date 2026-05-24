/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:11:42 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/11 14:33:06 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	ret;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		ret = ft_putchar(str[i]);
		if (ret == -1)
			return (-1);
		i++;
	}
	return (i);
}
