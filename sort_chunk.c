/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:54:10 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/29 13:08:46 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	int	chunk_size;

	chunk_size = 1;
	while (chunk_size * chunk_size < size)
		chunk_size++;
	return (chunk_size);
}

void	medium_sort(t_stack **a, t_stack **b, t_option *opt)
{
	int	size;
	int	chunk_size;

	size = stack_size(*a);
	chunk_size = get_chunk_size(size);
	push_chunks_to_b(a, b, chunk_size, opt);
	push_back_to_a(a, b, opt);
}
