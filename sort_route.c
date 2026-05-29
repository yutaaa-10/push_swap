/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:44:29 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/29 17:19:40 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	route_sort(t_stack **a, t_stack **b, t_option *opt)
{
	int	size;

	if (!a || !*a || stack_size(*a) <= 1)
		return ;
	size = stack_size(*a);
	if (size == 2)
		return (sort_two(a, opt));
	if (size == 3)
		return (sort_three(a, opt));
	if (size <= 5)
		return (sort_five(a, b, opt));
	if (opt->has_strategy)
	{
		if (opt->strategy == STRATEGY_SIMPLE)
			return (simple_sort(a, b, opt));
		if (opt->strategy == STRATEGY_MEDIUM)
			return (medium_sort(a, b, opt));
		if (opt->strategy == STRATEGY_COMPLEX)
			return (radix(a, b, opt));
	}
	if (size <= 100)
		return (medium_sort(a, b, opt));
	return (radix(a, b, opt));
}
