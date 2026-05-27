/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 23:08:20 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/27 15:42:06 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	handle_flag(char *s, t_option *opt)
{
	if (!ft_strncmp(s, "--bench", 8))
	{
		opt->bench = 1;
		return (1);
	}
	if (is_strategy_flag(s))
	{
		if (opt->has_strategy != 0)
			return (0);
		opt->has_strategy = 1;
		if (!ft_strncmp(s, "--simple", 9))
			opt->strategy = STRATEGY_SIMPLE;
		else if (!ft_strncmp(s, "--medium", 9))
			opt->strategy = STRATEGY_MEDIUM;
		else if (!ft_strncmp(s, "--complex", 10))
			opt->strategy = STRATEGY_COMPLEX;
		else
			opt->strategy = STRATEGY_ADAPTIVE;
		return (1);
	}
	return (0);
}

int	is_strategy_flag(char *s)
{
	if (!ft_strncmp(s, "--simple", 9))
		return (1);
	if (!ft_strncmp(s, "--medium", 9))
		return (1);
	if (!ft_strncmp(s, "--complex", 10))
		return (1);
	if (!ft_strncmp(s, "--adaptive", 11))
		return (1);
	return (0);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	parse_number(t_stack **a, char *s)
{
	long	num;
	t_stack	*new;

	if (!number_check(s))
		return (print_error(), 0);
	num = ft_atol(s);
	if (num < -2147483648L || num > 2147483647L)
		return (print_error(), 0);
	if (has_duplicate(*a, (int)num))
		return (print_error(), 0);
	new = stack_new((int)num);
	if (!new)
		return (print_error(), 0);
	stack_add_back(a, new);
	return (1);
}

static int	parse_split(t_stack **a, char **split)
{
	int	i;

	i = 0;
	if (!split || !split[0])
		return (0);
	while (split[i])
	{
		if (!parse_number(a, split[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(t_stack **a, int argc, char **argv, t_option *opt)
{
	int		i;
	char	**split;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && !number_check(argv[i]))
		{
			if (!handle_flag(argv[i], opt))
				return (print_error(), 0);
		}
		else
		{
			split = ft_split(argv[i], ' ');
			if (!parse_split(a, split))
				return (free_split(split), 0);
			free_split(split);
		}
		i++;
	}
	if (!*a)
		return (print_error(), 0);
	return (1);
}
