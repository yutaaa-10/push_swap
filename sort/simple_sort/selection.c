/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:18:48 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/26 12:31:47 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	find_min_position(t_stack *a)
{
	int	min;
	int	pos;
	int	min_pos;

	if (!a)
		return (0);
	min = a->value;
	pos = 0;
	min_pos = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			min_pos = pos;
		}
		a = a->next;
		pos++;
	}
	return (min_pos);
}

void	rotate_min_to_top(t_stack **a, int min_pos, int size)
{
	int	count;

	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a, 1);
	}
	else
	{
		count = size - min_pos;
		while (count-- > 0)
			rra(a, 1);
	}
}
void	simple_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	min_pos;

	while (*a)
	{
		size = stack_size(*a);
		min_pos = find_min_position(*a);
		rotate_min_to_top(a, min_pos, size);
		pb(a, b, 1);
	}
	while (*b != NULL)
		pa(a, b, 1);
}
