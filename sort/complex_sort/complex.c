/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:28:57 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/28 16:05:54 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	list_count(t_stack *a)
{
	int	count;

	count = 0;
	while (a != NULL)
	{
		count++;
		a = a->next;
	}
	return (count);
}

static int	get_max_pos(t_stack *b, int target)
{
	int	current_pos;

	current_pos = 0;
	while (b != NULL)
	{
		if (b->index == target)
		{
			return (current_pos);
		}
		current_pos++;
		b = b->next;
	}
	return (0);
}

static void	return_to_a(t_stack **a, t_stack **b, t_option *opt)
{
	int	size_b;
	int	max_pos;
	int	target;
	int	pushed_next;

	target = list_count(*b) - 1;
	while (*b != NULL)
	{
		pushed_next = 0;
		size_b = list_count(*b);
		max_pos = get_max_pos(*b, target);
		if (max_pos <= size_b / 2)
		{
			while ((*b)->index != target)
			{
				if ((*b)->index == target - 1)
				{
					pa(a, b, 1, opt);
					pushed_next++;
				}
				else
					rb(b, 1, opt);
			}
		}
		else
		{
			while ((*b)->index != target)
			{
				if ((*b)->index == target - 1)
				{
					pa(a, b, 1, opt);
					pushed_next++;
				}
				else
					rrb(b, 1, opt);
			}
		}
		pa(a, b, 1, opt);
		if (pushed_next == 1)
		{
			sa(a, 1, opt);
			target = target - 2;
		}
		else
			target = target - 1;
	}
}

void	complex_sort(t_stack **a, t_stack **b, t_option *opt)
{
	int	size;
	int	chunk;
	int	pushed;
	int	pivot;

	size = list_count(*a);
	if (size <= 100)
		chunk = 15;
	else
		chunk = 40;
	pivot = chunk;
	pushed = 0;
	while (*a != NULL)
	{
		if ((*a)->index < pivot)
		{
			pb(a, b, 1, opt);
			if (list_count(*b) > 1 && (*b)->index < pivot - (chunk / 2))
				rb(b, 1, opt);
			pushed++;
			if (pushed == pivot)
				pivot = pivot + chunk;
		}
		else
			ra(a, 1, opt);
	}
	return_to_a(a, b, opt);
}
