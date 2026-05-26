/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:23:12 by hdobashi          #+#    #+#             */
/*   Updated: 2026/05/26 20:13:36 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void fill_index(t_stack *a)
{
    t_stack *current;
    t_stack *compare;
    int count;

    current = a;
    while(current)
    {
        count = 0;
        compare = a;
        while(compare)
        {
            if(compare->value < current->value)
                count++;
            compare = compare->next;
        }
        current->index = count;
        current = current->next;
    }
}