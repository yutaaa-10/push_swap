/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:01:37 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/24 14:53:29 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	has_duplicate(t_stack *a, int value)
{
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}
