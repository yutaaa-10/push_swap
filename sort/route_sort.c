/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:44:29 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/28 16:56:16 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	route_sort(t_stack **a, t_stack **b, t_option *opt)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a, opt);
	else if (size == 3)
		sort_three(a, opt);
	else if (size <= 5)
		sort_five(a, b, opt);
	else if (opt->strategy == STRATEGY_SIMPLE)
		simple_sort(a, b, opt);
	else if (opt->strategy == STRATEGY_MEDIUM)
		medium_sort(a, b, opt);
	else if (opt->strategy == STRATEGY_COMPLEX)
		radix(a, b, opt);
	else
		adaptive_sort(a, b, opt);
}
