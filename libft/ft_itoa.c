/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:10:20 by yukurosa          #+#    #+#             */
/*   Updated: 2026/04/30 12:07:32 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n)
{
	long	nb;
	int		len;

	len = 0;
	nb = n;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*res;

	nb = n;
	len = count_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		len--;
		res[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}
