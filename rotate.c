/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:29:22 by srusso-b          #+#    #+#             */
/*   Updated: 2026/02/23 23:43:33 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack == NULL || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack *stack)
{
	if (stack == NULL || stack->size < 2)
		return ;
	op_rotate(stack);
	ft_putstr("ra\n");
}

void	rb(t_stack *stack)
{
	if (stack == NULL || stack->size < 2)
		return ;
	op_rotate(stack);
	ft_putstr("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	op_rotate(a);
	op_rotate(b);
	ft_putstr("rr\n");
}
