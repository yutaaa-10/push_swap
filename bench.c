/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:03:21 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/29 14:28:57 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder_value(double disorder)
{
	int	value;

	value = (int)(disorder * 100 + 0.5);
	ft_putnbr_fd(value / 100, 2);
	ft_putchar_fd('.', 2);
	if (value % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(value % 100, 2);
}

char	*get_strategy_name(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("Simple");
	if (strategy == STRATEGY_MEDIUM)
		return ("Medium");
	if (strategy == STRATEGY_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*get_complexity_name(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRATEGY_MEDIUM)
		return ("O(n√n)");
	if (strategy == STRATEGY_COMPLEX)
		return ("O(n log n)");
	return ("adaptive");
}
