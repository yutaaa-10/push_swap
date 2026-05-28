/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 23:25:50 by hdobashi          #+#    #+#             */
/*   Updated: 2026/05/28 13:40:21 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a, int print, t_option *opt)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	if (opt)
	{
		opt->count.ra++;
		opt->count.total++;
	}
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int print, t_option *opt)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	first->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	if (opt)
	{
		opt->count.rb++;
		opt->count.total++;
	}
	if (print)
		write(1, "rb\n", 3);
}
void	rr(t_stack **a, t_stack **b, t_option *opt)
{
	ra(a, 0, opt);
	rb(b, 0, opt);
	if (opt)
	{
		opt->count.ra--;
		opt->count.rb--;
		opt->count.total -= 2;
		opt->count.rr++;
		opt->count.total++;
	}
	write(1, "rr\n", 3);
}
