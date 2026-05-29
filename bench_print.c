/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:27:46 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/29 14:32:51 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_bench_header(t_option *opt)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder_value(opt->disorder);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(get_strategy_name(opt->strategy), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(get_complexity_name(opt->selected_strategy), 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(opt->count.total, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_bench_swap_push(t_option *opt)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(opt->count.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(opt->count.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(opt->count.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(opt->count.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(opt->count.pb, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_bench_rotate(t_option *opt)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(opt->count.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(opt->count.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(opt->count.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(opt->count.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(opt->count.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(opt->count.rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	print_benchmark(t_option *opt)
{
	if (!opt || !opt->bench)
		return ;
	print_bench_header(opt);
	print_bench_swap_push(opt);
	print_bench_rotate(opt);
}
