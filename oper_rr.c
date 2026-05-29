/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 23:25:55 by hdobashi          #+#    #+#             */
/*   Updated: 2026/05/29 13:08:08 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int print, t_option *opt)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!a || !*a || !(*a)->next)
		return ;
	second_last = *a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	if (opt)
	{
		opt->count.rra++;
		opt->count.total++;
	}
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print, t_option *opt)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!b || !*b || !(*b)->next)
		return ;
	second_last = *b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *b;
	*b = last;
	if (opt)
	{
		opt->count.rrb++;
		opt->count.total++;
	}
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, t_option *opt)
{
	rra(a, 0, opt);
	rrb(b, 0, opt);
	if (opt)
	{
		opt->count.rra--;
		opt->count.rrb--;
		opt->count.total -= 2;
		opt->count.rrr++;
		opt->count.total++;
	}
	write(1, "rrr\n", 4);
}
