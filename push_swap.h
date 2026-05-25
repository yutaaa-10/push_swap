/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:38:53 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/25 17:02:50 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef enum e_strategy
{
	STRATEGY_ADAPTIVE,
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX
}					t_strategy;

typedef struct s_option
{
	int				bench;
	t_strategy		strategy;
	int				has_strategy;
}					t_option;

// error
void				print_error(void);
int					number_check(char *s);
long				ft_atol(const char *s);
int					has_duplicate(t_stack *a, int value);

// input_parse
int					parse_args(t_stack **a, int argc, char **argv,
						t_option *opt);
int					handle_flag(char *s, t_option *opt);
int					is_strategy_flag(char *s);
void				init_option(t_option *opt);

// operations
void				sa(t_stack **a, int print);
void				sb(t_stack **b, int print);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b, int print);
void				pb(t_stack **a, t_stack **b, int print);
void				ra(t_stack **a, int print);
void				rb(t_stack **b, int print);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a, int print);
void				rrb(t_stack **b, int print);
void				rrr(t_stack **a, t_stack **b);

// stack
t_stack				*stack_new(int value);
void				stack_add_back(t_stack **stack, t_stack *new);
void				free_stack(t_stack *stack);
int					stack_size(t_stack *stack);

// main
void				print_stack(t_stack *stack);

// sort route
void				route_sort(t_stack **a, t_stack **b, t_option *opt);

// small sort
void				sort_two(t_stack **a);
void				sort_three(t_stack **a);
void				sort_five(t_stack **a, t_stack **b);

// strategy sort
void				simple_sort(t_stack **a, t_stack **b);
void				medium_sort(t_stack **a, t_stack **b);
void				complex_sort(t_stack **a, t_stack **b);
void				adaptive_sort(t_stack **a, t_stack **b);

// adaptive sort
double				calculate_disorder(t_stack *a);

#endif
