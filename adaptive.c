/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:02:36 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/29 16:07:54 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	set_strategy(t_stack **a, t_stack **b, t_option *opt, double score)
{
	if (score < 0.2)
	{
		opt->selected_strategy = STRATEGY_SIMPLE;
		simple_sort(a, b, opt);
	}
	else if (score < 0.5)
	{
		opt->selected_strategy = STRATEGY_MEDIUM;
		medium_sort(a, b, opt);
	}
	else
	{
		opt->selected_strategy = STRATEGY_COMPLEX;
		radix(a, b, opt);
	}
}

void	adaptive_sort(t_stack **a, t_stack **b, t_option *opt)
{
	double	score;

	if (!a || !*a || !opt)
		return ;
	score = calculate_disorder(*a);
	opt->disorder = score * 100.0;
	set_strategy(a, b, opt, score);
}
