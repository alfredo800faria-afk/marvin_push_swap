/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:34:01 by srusso-b          #+#    #+#             */
/*   Updated: 2026/02/23 05:47:13 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_reverse(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (stack == NULL)
		return ;
	if (stack->size >= 2)
	{
		first = stack->top;
		last = stack->top;
		second = NULL;
		while (last->next)
		{
			second = last;
			last = last->next;
		}
		second->next = NULL;
		last->next = first;
		stack->top = last;
	}
}

void	rra(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = first;
	stack->top = last;
	ft_putstr("rra\n");
}

void	rrb(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = first;
	stack->top = last;
	ft_putstr("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	op_reverse(a);
	op_reverse(b);
	ft_putstr("rrr\n");
}
