/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serection_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:02:44 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/28 15:06:48 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	find_max_position(t_stack *b)
{
	int	max;
	int	pos;
	int	max_pos;

	if (!b)
		return (0);
	max = b->index;
	pos = 0;
	max_pos = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			max_pos = pos;
		}
		b = b->next;
		pos++;
	}
	return (max_pos);
}

void	push_chunks_to_b(t_stack **a, t_stack **b, int chunk_size,
		t_option *opt)
{
	int	start;
	int	end;
	int	pushed;

	start = 0;
	end = chunk_size - 1;
	pushed = 0;
	while (*a)
	{
		if ((*a)->index >= start && (*a)->index <= end)
		{
			pb(a, b, 1, opt);
			pushed++;
			if ((*b)->index < start + (chunk_size / 2))
				rb(b, 1, opt);
		}
		else
			ra(a, 1, opt);
		if (pushed > end)
		{
			start += chunk_size;
			end += chunk_size;
		}
	}
}

void	rotate_max_to_top(t_stack **b, int max_pos, int size, t_option *opt)
{
	int	count;

	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
			rb(b, 1, opt);
	}
	else
	{
		count = size - max_pos;
		while (count-- > 0)
			rrb(b, 1, opt);
	}
}

void	push_back_to_a(t_stack **a, t_stack **b, t_option *opt)
{
	int	size;
	int	max_pos;

	while (*b)
	{
		size = stack_size(*b);
		max_pos = find_max_position(*b);
		rotate_max_to_top(b, max_pos, size, opt);
		pa(a, b, 1, opt);
	}
}
