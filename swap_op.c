/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:11:04 by srusso-b          #+#    #+#             */
/*   Updated: 2026/02/23 04:03:49 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	ft_putstr("sa\n");
}

void	sb(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	ft_putstr("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	t_node	*first_a;
	t_node	*second_a;
	t_node	*first_b;
	t_node	*second_b;

	if (a->size >= 2)
	{
		first_a = a->top;
		second_a = a->top->next;
		first_a->next = second_a->next;
		second_a->next = first_a;
		a->top = second_a;
	}
	if (b->size >= 2)
	{
		first_b = b->top;
		second_b = b->top->next;
		first_b->next = second_b->next;
		second_b->next = first_b;
		b->top = second_b;
	}
	ft_putstr("ss\n");
}
