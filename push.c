/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:21:45 by srusso-b          #+#    #+#             */
/*   Updated: 2026/02/23 04:10:17 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* PUSH OPERATIONS */
void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->size == 0)
		return ;
	temp = b->top;
	b->top = b->top->next;
	b->size--;
	temp->next = a->top;
	a->top = temp;
	a->size++;
	ft_putstr("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->size == 0)
		return ;
	temp = a->top;
	a->top = a->top->next;
	a->size--;
	temp->next = b->top;
	b->top = temp;
	b->size++;
	ft_putstr("pb\n");
}
