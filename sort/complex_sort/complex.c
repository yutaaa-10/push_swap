/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:28:57 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/27 21:44:12 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int list_count(t_stack *a)
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

static int get_max_pos(t_stack *b,int target)
{
	int current_pos;

	current_pos = 0;
	while(b !=NULL)
	{
		if(b->index == target)
		{
			return(current_pos);
		}
		current_pos++;
		b= b->next;
	}
	return(0);
}

static void return_to_a(t_stack **a,t_stack **b)
{
	int size_b;
	int max_pos;
	int target;
	int pushed_next;

	target = list_count(*b) - 1;
	while(*b !=NULL)
	{
		pushed_next = 0;
		size_b=list_count(*b);
		max_pos = get_max_pos(*b,target);
		if(max_pos <=size_b/2)
		{
			while((*b)->index != target)
			{
				if((*b)->index == target -1)
				{
					pa(a,b,1);
					pushed_next++;
				}
				rb(b,1);
			}
		}
		else
		{
			while((*b)->index != target)
			{
				if((*b)->index != target -1)
				{
					pa(a,b,1);
					pushed_next++;
				}
				rrb(b,1);
				max_pos++;
			}
		}
		pa(a,b,1);
		if(pushed_next == 1)
		{
			sa(a,1);
			target = target -2;
		}
		else
			target = target - 1;
	}
}

void	complex_sort(t_stack **a, t_stack **b)
{
	int size;
	int chunk;
	int count;
	
	size = list_count(*a);
	if(size <= 100)
		chunk = 15;
	else
		chunk = 40;
	count = 0;

	while(*a != NULL)
	{
		if((*a)->index <= count )
		{
			pb(a,b,1);
			rb(b,1);
			count++;
		}
		else if((*a)->index <=count +chunk)
		{
			pb(a,b,1);
			count++;
		}
		else
			ra(a,1);
	}
	return_to_a(a,b);
}
