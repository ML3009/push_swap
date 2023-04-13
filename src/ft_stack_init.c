/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:09:07 by mvautrot          #+#    #+#             */
/*   Updated: 2023/04/13 15:27:22 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stack_init(t_vars *var, t_lst **stack_a, t_lst **stack_tmp)
{
	int		i;
	int		temp;
	t_lst	*tmp;

	i = 0;
	while (i < var->size)
	{
		temp = ft_atoi(var->tmp_lst[i]);
		tmp = ft_new_element(temp);
		ft_add_back_lst(stack_a, tmp);
		i++;
	}
	i = 0;
	while (i < var->size)
	{
		temp = ft_atoi(var->tmp_lst[i]);
		tmp = ft_new_element(temp);
		ft_add_back_lst(stack_tmp, tmp);
		i++;
	}
	if (var->ac == 2)
		ft_free_tab(var->tmp_lst);
	else
		free(var->tmp_lst);
}

int	ft_get_min(t_lst *stack)
{
	t_lst	*tmp;
	int		min;

	tmp = stack;
	min = stack->content;
	while (stack->next)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	if (stack->content < min)
		min = stack->content;
	stack = tmp;
	return (min);
}

int	ft_get_max(t_lst *stack)
{
	t_lst	*tmp;
	int		max;

	tmp = stack;
	max = stack->content;
	while (stack->next)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	if (stack->content > max)
		max = stack->content;
	stack = tmp;
	return (max);
}
