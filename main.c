/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:49:54 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/26 13:13:08 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_option(t_option *opt)
{
	opt->bench = 0;
	opt->strategy = STRATEGY_ADAPTIVE;
	opt->has_strategy = 0;
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_option	opt;
	int			i;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	i = 0;
	init_option(&opt);
	if (!parse_args(&a, argc, argv, &opt))
	{
		free_stack(a);
		return (1);
	}
	route_sort(&a, &b, &opt);
	free_stack(a);
	free_stack(b);
	return (0);
}
