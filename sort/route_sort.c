/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:44:29 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/24 14:01:10 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	route_sort(t_stack **a, t_stack **b, t_option *opt)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else if (opt->strategy == STRATEGY_SIMPLE)
		simple_sort(a, b);
	else if (opt->strategy == STRATEGY_MEDIUM)
		medium_sort(a, b);
	else if (opt->strategy == STRATEGY_COMPLEX)
		complex_sort(a, b);
	else
		adaptive_sort(a, b);
}
