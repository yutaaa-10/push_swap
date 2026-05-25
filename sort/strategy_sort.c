/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:50:59 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/25 15:41:04 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simple_sort(t_stack **a, t_stack **b)
{
	(void)a;
	(void)b;
}

void	medium_sort(t_stack **a, t_stack **b)
{
	(void)a;
	(void)b;
}

void	complex_sort(t_stack **a, t_stack **b)
{
	(void)a;
	(void)b;
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
