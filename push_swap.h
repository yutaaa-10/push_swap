/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:38:53 by yukurosa          #+#    #+#             */
/*   Updated: 2026/05/28 21:17:55 by yukurosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_count
{
	int				total;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_count;

typedef struct s_option
{
	int				bench;
	double			disorder;
	t_strategy		strategy;
	int				has_strategy;
	t_count			count;
}					t_option;

typedef struct s_three
{
	int				first;
	int				second;
	int				third;
}					t_three;

// bench
void				print_benchmark(t_option *opt);

// disorder
void				adaptive_sort(t_stack **a, t_stack **b, t_option *opt);
double				calculate_disorder(t_stack *a);

// error
void				print_error(void);
int					number_check(char *s);
long				ft_atol(const char *s);
int					has_duplicate(t_stack *a, int value);

// input_parse
int					parse_args(t_stack **a, int argc, char **argv,
						t_option *opt);
void				fill_index(t_stack *a);
int					handle_flag(char *s, t_option *opt);
int					is_strategy_flag(char *s);
void				free_split(char **split);
int					parse_split(t_stack **a, char **split);
int					parse_number(t_stack **a, char *s);

// operations
void				sa(t_stack **a, int print, t_option *opt);
void				sb(t_stack **b, int print, t_option *opt);
void				ss(t_stack **a, t_stack **b, t_option *opt);
void				pa(t_stack **a, t_stack **b, int print, t_option *opt);
void				pb(t_stack **a, t_stack **b, int print, t_option *opt);
void				ra(t_stack **a, int print, t_option *opt);
void				rb(t_stack **b, int print, t_option *opt);
void				rr(t_stack **a, t_stack **b, t_option *opt);
void				rra(t_stack **a, int print, t_option *opt);
void				rrb(t_stack **b, int print, t_option *opt);
void				rrr(t_stack **a, t_stack **b, t_option *opt);

// stack
t_stack				*stack_new(int value);
void				stack_add_back(t_stack **stack, t_stack *new);
void				free_stack(t_stack *stack);
int					stack_size(t_stack *stack);

// main
void				print_stack(t_stack *stack);
void				init_option(t_option *opt);

// sort route
void				route_sort(t_stack **a, t_stack **b, t_option *opt);

// small sort
void				sort_two(t_stack **a, t_option *opt);
void				sort_three(t_stack **a, t_option *opt);
void				sort_five(t_stack **a, t_stack **b, t_option *opt);
int					is_sorted(t_stack *a);
// strategy sort

// simple sort
void				simple_sort(t_stack **a, t_stack **b, t_option *opt);
void				rotate_min_to_top(t_stack **a, int min_pos, int size,
						t_option *opt);
int					find_min_position(t_stack *a);

// medium sort
void				medium_sort(t_stack **a, t_stack **b, t_option *opt);
void				push_back_to_a(t_stack **a, t_stack **b, t_option *opt);
void				rotate_max_to_top(t_stack **b, int max_pos, int size,
						t_option *opt);
void				push_chunks_to_b(t_stack **a, t_stack **b, int chunk_size,
						t_option *opt);

// complex sort
void				radix(t_stack **a, t_stack **b, t_option *opt);
#endif
