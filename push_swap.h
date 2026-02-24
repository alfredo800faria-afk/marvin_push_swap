/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:08:02 by srusso-b          #+#    #+#             */
/*   Updated: 2026/02/23 23:36:41 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* INCLUDES */
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* STRUCTURES */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* --- Main Functions --- */
int		main(int argc, char **argv);
int		parse_args(int argc, char **argv, t_stack *stack_a);
int		parse_single_number(char *str, t_stack *stack);
int		parse_string(char *str, t_stack *stack_a);
int		is_valid_number(char *str);
long	ft_atol(const char *str);
int		add_to_stack(t_stack *stack, int value);
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		count_words(char *str);
void	print_error(void);
void	push_min_to_b(t_stack *a, t_stack *b);
void	assign_indexes(t_stack *stack);
void	free_stack(t_stack *stack);
void	sort_four(t_stack *a, t_stack *b);
void	ft_putchar(char c);
void	ft_putstr(char *str);

/* --- Stack Operations --- */
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);

/* --- Sorting Functions --- */
void	sort_stack(t_stack *a, t_stack *b);
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);
int		find_min_index(t_stack *stack);
int		get_max_bits(t_stack *stack);

#endif
