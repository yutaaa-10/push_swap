/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:10:29 by hdobashi          #+#    #+#             */
/*   Updated: 2026/05/28 17:00:14 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static int	get_max_bite(t_stack *a)
{
	int	max_index;
	int	bit;

	max_index = 0;
	bit = 0;
	while (a != NULL)
	{
		if (max_index < a->index)
			max_index = a->index;
		a = a->next;
	}
	while (max_index >> bit)
		bit++;
	return (bit);
}

void	radix(t_stack **a, t_stack **b, t_option *opt)
{
	int	i;
	int	j;
	int	size;
	int	max;

	size = list_count(*a);
	max = get_max_bite(*a);
	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < size)
		{
			if ((*a)->index >> i & 1)
				ra(a, 1, opt);
			else
				pb(a, b, 1, opt);
			j++;
		}
		while (*b != NULL)
			pa(a, b, 1, opt);
		i++;
	}
}
