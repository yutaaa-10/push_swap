/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:44:29 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/29 18:47:47 by yukurosa         ###   ########.fr       */
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
	if (opt->strategy == STRATEGY_ADAPTIVE)
		adaptive_sort(a, b, opt);
	else if (opt->strategy == STRATEGY_SIMPLE)
		simple_sort(a, b, opt);
	else if (opt->strategy == STRATEGY_MEDIUM)
		medium_sort(a, b, opt);
	else if (opt->strategy == STRATEGY_COMPLEX)
		radix(a, b, opt);
}
