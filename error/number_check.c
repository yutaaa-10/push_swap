/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:02:27 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/24 14:55:36 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	number_check(char *s)
{
	int	i;

	i = 0;
	if (s == NULL || s[0] == '\0')
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *s)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * sign);
}
