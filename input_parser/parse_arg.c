/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 23:08:20 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/22 23:16:06 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	parse_args(t_stack **a, int argc, char **argv)
{
	int		i;
	int		value;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new = stack_new(value);
		stack_add_back(a, new);
		i++;
	}
}
