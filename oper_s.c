/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 23:25:59 by hdobashi          #+#    #+#             */
/*   Updated: 2026/05/29 13:08:13 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int print, t_option *opt)
{
	t_stack	*first;
	t_stack	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	if (opt)
	{
		opt->count.sa++;
		opt->count.total++;
	}
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int print, t_option *opt)
{
	t_stack	*first;
	t_stack	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	if (opt)
	{
		opt->count.sb++;
		opt->count.total++;
	}
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, t_option *opt)
{
	sa(a, 0, opt);
	sb(b, 0, opt);
	if (opt)
	{
		opt->count.sa--;
		opt->count.sb--;
		opt->count.total -= 2;
		opt->count.ss++;
		opt->count.total++;
	}
	write(1, "ss\n", 3);
}
