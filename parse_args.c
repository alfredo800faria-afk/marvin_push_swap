/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:45:21 by srusso-b          #+#    #+#             */
/*   Updated: 2026/02/23 23:40:18 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_single_number(char *str, t_stack *stack)
{
	long	value;
	int		i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!is_valid_number(str))
		return (0);
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	if (!add_to_stack(stack, (int)value))
		return (0);
	return (1);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	if (argc == 2)
	{
		if (!parse_string(argv[1], stack_a))
			print_error();
		return (1);
	}
	i = argc - 1;
	while (i >= 1)
	{
		if (count_words(argv[i]) > 1)
		{
			if (!parse_string(argv[i], stack_a))
				print_error();
		}
		else
		{
			if (!parse_single_number(argv[i], stack_a))
				print_error();
		}
		i--;
	}
	return (1);
}

int	parse_string(char *str, t_stack *stack_a)
{
	char	*ptr;
	long	value;
	int		temp[10000];
	int		count;
	int		i;

	count = 0;
	ptr = str;
	while (*ptr)
	{
		value = ft_atol(ptr);
		if (value > INT_MAX || value < INT_MIN || count >= 10000)
			return (0);
		temp[count] = (int)value;
		count++;
	}
	i = count;
	while (--i >= 0)
		if (!add_to_stack(stack_a, temp[i]))
			return (0);
	return (1);
}
