/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 09:22:02 by srusso-b          #+#    #+#             */
/*   Updated: 2026/02/23 06:53:24 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	int	t;
	int	m;
	int	b;

	t = stack->top->value;
	m = stack->top->next->value;
	b = stack->top->next->next->value;
	if (t > m && m > b)
	{
		sa(stack);
		rra(stack);
	}
	else if (t > m && t > b && m < b)
		ra(stack);
	else if (t < m && t > b)
		rra(stack);
	else if (t > m && t < b)
		sa(stack);
	else if (t < m && m > b && t < b)
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}
