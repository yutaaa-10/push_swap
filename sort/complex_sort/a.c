/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:28:57 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/27 18:35:52 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int list_count(t_stack *a)
{
	int count ;
	count = 0;
	while(a !=NULL)
	{
		count++;
		a = a->next;
	}
	return(count);
}

int get_max_pos(t_stack *b)
{
	int max_pos;
	int max_index;
	int current_pos;

	max_index = -1;
	max_pos =0;
	current_pos = 0;
	while(b !=NULL)
	{
		if(b->index > max_index)
		{
			max_index = b->index;
			max_pos = current_pos;
		}
		current_pos++;
		b= b->next;
	}
	return(max_pos);
}

void return_to_a(t_stack **a,t_stack **b)
{
	int size_b;
	int max_pos;

	while(*b !=NULL)
	{
		size_b=list_count(*b);
		max_pos = get_max_pos(*b);
		if(max_pos <=size_b/2)
		{
			while(max_pos > 0)
			{
				rb(b,1);
				max_pos--;
			}
		}
		else
		{
			while(max_pos < size_b)
			{
				rrb(b,1);
				max_pos++;
			}
		}
		pa(a,b,1);
	}
}
void	complex_sort(t_stack **a, t_stack **b)
{
	int pivot;
	int size;
	int chunk;
	int pushed;
	
	size = list_count(*a);
	if(size <= 100)
		chunk = size/5;
	else
		chunk = size /12;
	pivot = chunk;
	pushed = 0;

	while(list_count(*a) >  3)
	{
		if((*a)->index < pivot )
		{
			pb(a,b,1);
			pushed++;
			if (pushed == pivot)
				pivot = pivot +chunk;
		}
		else
			ra(a,1);
	}
	sort_three(a);
	return_to_a(a,b);
}
