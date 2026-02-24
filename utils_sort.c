/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:44:12 by srusso-b          #+#    #+#             */
/*   Updated: 2026/02/23 21:36:30 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		min_value;
	int		min_index;
	int		i;

	current = stack->top;
	min_value = current->value;
	min_index = 0;
	i = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

int	get_max_bits(t_stack *stack)
{
	int		max_index;
	int		bits;
	t_node	*current;

	max_index = 0;
	current = stack->top;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	size;

	min_pos = find_min_index(a);
	size = a->size;
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
	pb(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		current_bit;
	int		i;
	int		size;
	t_node	*node;

	max_bits = get_max_bits(a);
	current_bit = 0;
	while (current_bit < max_bits)
	{
		size = a->size;
		i = 0;
		while (i < size)
		{
			node = a->top;
			if ((node->index >> current_bit) & 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		current_bit++;
	}
}
