/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:40:26 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/28 18:17:41 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_disorder(double disorder)
{
	int	value;

	value = (int)(disorder * 100 + 0.5);
	ft_putstr_fd("Disorder: ", 2);
	ft_putnbr_fd(value / 100, 2);
	ft_putchar_fd('.', 2);
	if (value % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(value % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static char	*get_strategy_name(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("simple");
	if (strategy == STRATEGY_MEDIUM)
		return ("medium");
	if (strategy == STRATEGY_COMPLEX)
		return ("complex");
	return ("adaptive");
}

static char	*get_complexity_name(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRATEGY_MEDIUM)
		return ("O(n sqrt(n))");
	if (strategy == STRATEGY_COMPLEX)
		return ("O(n log n)");
	return ("adaptive");
}

static void	print_count(char *name, int count)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
	ft_putchar_fd('\n', 2);
}

void	print_benchmark(t_option *opt)
{
	if (!opt || !opt->bench)
		return ;
	print_disorder(opt->disorder);
	ft_putstr_fd("Strategy: ", 2);
	ft_putstr_fd(get_strategy_name(opt->strategy), 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("Complexity: ", 2);
	ft_putstr_fd(get_complexity_name(opt->strategy), 2);
	ft_putchar_fd('\n', 2);
	print_count("Total operations", opt->count.total);
	print_count("sa", opt->count.sa);
	print_count("sb", opt->count.sb);
	print_count("ss", opt->count.ss);
	print_count("pa", opt->count.pa);
	print_count("pb", opt->count.pb);
	print_count("ra", opt->count.ra);
	print_count("rb", opt->count.rb);
	print_count("rr", opt->count.rr);
	print_count("rra", opt->count.rra);
	print_count("rrb", opt->count.rrb);
	print_count("rrr", opt->count.rrr);
}
