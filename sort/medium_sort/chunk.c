/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:54:10 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/28 13:33:27 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	get_chunk_size(int size)
{
	int	chunk_size;

	chunk_size = 1;
	while (chunk_size * chunk_size < size)
		chunk_size++;
	return (chunk_size);
}

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
	int	size;

	start = 0;
	end = chunk_size - 1;
	pushed = 0;
	size = stack_size(*a);
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
			if (end >= size)
				end = size - 1;
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

void	medium_sort(t_stack **a, t_stack **b, t_option *opt)
{
	int	size;
	int	chunk_size;

	size = stack_size(*a);
	chunk_size = get_chunk_size(size);
	push_chunks_to_b(a, b, chunk_size, opt);
	push_back_to_a(a, b, opt);
}
