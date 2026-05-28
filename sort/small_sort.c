/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:50:43 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/28 17:49:24 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **a, t_option *opt)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if ((*a)->value > (*a)->next->value)
		sa(a, 1, opt);
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	sort_three_case(t_stack **a, t_option *opt, t_three n)
{
	if (n.first > n.second && n.second < n.third && n.first < n.third)
		sa(a, 1, opt);
	else if (n.first > n.second && n.second > n.third)
	{
		sa(a, 1, opt);
		rra(a, 1, opt);
	}
	else if (n.first > n.second && n.second < n.third && n.first > n.third)
		ra(a, 1, opt);
	else if (n.first < n.second && n.second > n.third && n.first < n.third)
	{
		sa(a, 1, opt);
		ra(a, 1, opt);
	}
	else if (n.first < n.second && n.second > n.third && n.first > n.third)
		rra(a, 1, opt);
}

void	sort_three(t_stack **a, t_option *opt)
{
	t_three	n;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	if (is_sorted(*a))
		return ;
	n.first = (*a)->value;
	n.second = (*a)->next->value;
	n.third = (*a)->next->next->value;
	sort_three_case(a, opt, n);
}

void	sort_five(t_stack **a, t_stack **b, t_option *opt)
{
	int	size;
	int	min_pos;

	if (!a || !*a)
		return ;
	while (stack_size(*a) > 3)
	{
		size = stack_size(*a);
		min_pos = find_min_position(*a);
		rotate_min_to_top(a, min_pos, size, opt);
		pb(a, b, 1, opt);
	}
	sort_three(a, opt);
	while (*b)
		pa(a, b, 1, opt);
}
