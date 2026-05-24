#include "push_swap"
#include <stdio.h>
#include <unistd.h>

int	parse_args(t_stack **a, int argc, char **argv, t_option *opt)
{
	int		i;
	long	num;
	t_stack	*new;

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
			if (!number_check(argv[i]))
				return (print_error(), 0);
			num = ft_atol(argv[i]);
			if (num < -2147483648L || num > 2147483647L)
				return (print_error(), 0);
			if (has_suplicate(*a, (int)num))
				return (print_error(), 0);
			new = stack_new((int)num);
			if (!new)
				return (print_error(), 0);
			stack_add_back(a, new);
		}
		i++;
	}
	if (!*a)
		return (print_error(), 0);
	return (0);
}

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
	if (!ft_strcmp(s, "--simple", 9))
		return (1);
	if (!ft_strcmp(s, "--medium", 9))
		return (1);
	if (!ft_strcmp(s, "--complex", 10))
		return (1);
	if (!ft_strcmp(s, "--adaptive", 11))
		return (1);
	return (0);
}
