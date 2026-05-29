/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:49:54 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/29 16:17:37 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_index(t_stack *a)
{
	t_stack	*current;
	t_stack	*compare;
	int		count;

	current = a;
	while (current)
	{
		count = 0;
		compare = a;
		while (compare)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->index = count;
		current = current->next;
	}
}

void	init_option(t_option *opt)
{
	opt->bench = 0;
	opt->strategy = STRATEGY_ADAPTIVE;
	opt->selected_strategy = STRATEGY_SIMPLE;
	opt->has_strategy = 0;
	opt->disorder = 0.0;
	opt->count.total = 0;
	opt->count.sa = 0;
	opt->count.sb = 0;
	opt->count.ss = 0;
	opt->count.pa = 0;
	opt->count.pb = 0;
	opt->count.ra = 0;
	opt->count.rb = 0;
	opt->count.rr = 0;
	opt->count.rra = 0;
	opt->count.rrb = 0;
	opt->count.rrr = 0;
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_option	opt;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	init_option(&opt);
	if (!parse_args(&a, argc, argv, &opt))
	{
		free_stack(a);
		return (1);
	}
	fill_index(a);
	if (opt.bench)
		opt.disorder = calculate_disorder(a) * 100.0;
	if (is_sorted(a))
		return (print_benchmark(&opt), free_stack(a), 0);
	route_sort(&a, &b, &opt);
	if (opt.bench)
		print_benchmark(&opt);
	free_stack(a);
	free_stack(b);
	return (0);
}
