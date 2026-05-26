/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:11:01 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/26 10:27:20 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	calculate_disorder(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	int		mistake;
	int		total;

	if (!a || !a->next)
		return (0.0);
	mistake = 0;
	total = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total++;
			if (i->value > j->value)
				mistake++;
			j = j->next;
		}
		i = i->next;
	}
	if (total == 0)
		return (0.0);
	return ((double)mistake / (double)total);
}

void	adaptive_sort(t_stack **a, t_stack **b)
{
	double	score;

	if (!a || !*a)
		return ;
	score = calculate_disorder(*a);
	if (score < 0.2)
		simple_sort(a, b);
	else if (score >= 0.2 && score < 0.5)
		medium_sort(a, b);
	else
		complex_sort(a, b);
}
