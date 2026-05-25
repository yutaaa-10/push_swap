/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:51:33 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/25 15:54:32 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	calculate_disorder(t_stack *a)
{
	int		misetake;
	int		size;
	t_stack	*cur;
	t_stack	*next;

	if (!a)
		return (0.0);
	size = stack_size(a);
	if (size <= 1)
		return (0.0);
	misetake = 0;
	cur = a;
	next = a->next;
	while (next != NULL)
	{
		if (cur->value > next->value)
			misetake++;
		cur = next;
		next = next->next;
	}
	return ((double)misetake / (double)(size - 1));
}
