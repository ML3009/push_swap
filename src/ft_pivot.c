/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:37:09 by ml                #+#    #+#             */
/*   Updated: 2023/04/13 14:41:13 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_quick(t_lst *stack_tmp, int mid)
{
	t_lst	*tmp;
	int		i;

	tmp = stack_tmp;
	i = 0;
	while (i < mid)
	{
	tmp = tmp->next;
		i++;
	}
	return (tmp->content);
}

int	ft_get_pivot(t_lst *stack_tmp, int mid)
{
	ft_get_index(stack_tmp);
	while (stack_tmp->next)
	{
		if (stack_tmp->index == mid)
			return (stack_tmp->content);
	stack_tmp = stack_tmp->next;
	}
	return (0);
}

int	ft_get_pivot_10(t_lst *stack)
{
	int	max;
	int	min;

	min = ft_get_min(stack);
	max = ft_get_max(stack);
	while (stack->next)
	{
		if (stack->content > min && stack->content < max)
			return (stack->content);
		stack = stack->next;
	}
	if (stack->content > min && stack->content < max)
		return (stack->content);
	return (0);
}

int	ft_get_position(t_lst *stack, int content)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp->content != content)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_get_index(t_lst *stack_tmp)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = stack_tmp;
	while (stack_tmp->next)
	{
		stack_tmp->index = i;
		stack_tmp = stack_tmp->next;
		i++;
	}
	stack_tmp->index = i;
	stack_tmp = tmp;
}
