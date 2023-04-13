/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_gestion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:32:38 by ml                #+#    #+#             */
/*   Updated: 2023/04/13 12:11:18 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_list(t_lst *stack_tmp)
{
	int		swap;
	t_lst	*tmp;

	tmp = stack_tmp;
	while (stack_tmp->next)
	{
		if (stack_tmp->content > stack_tmp->next->content)
		{
			swap = stack_tmp->content;
			stack_tmp->content = stack_tmp->next->content;
			stack_tmp->next->content = swap;
			stack_tmp = tmp;
		}
		else
			stack_tmp = stack_tmp->next;
	}
	stack_tmp = tmp;
}

int	ft_sort_same(t_lst *stack_a, t_lst *stack_tmp, t_vars *var)
{
	t_lst	*tmp_a;
	t_lst	*tmp;
	int		i;

	tmp_a = stack_a;
	tmp = stack_tmp;
	i = 0;
	while (i < var->size)
	{
		if (stack_a->content != stack_tmp->content)
		{
			stack_a = tmp_a;
			stack_tmp = tmp;
			return (0);
		}
		stack_a = stack_a->next;
		stack_tmp = stack_tmp->next;
		i++;
	}
	return (1);
}

void	ft_sort_3(t_lst	**stack_a, int pivot, t_vars *var)
{
	if (ft_check_sorting_stack(stack_a, 3))
		return ;
	if ((*stack_a)->content > pivot && (*stack_a)->next->content < pivot)
		ft_ra((*stack_a), 1, var);
	else if ((*stack_a)->content == pivot)
	{
		if ((*stack_a)->next->content < pivot)
			ft_sa((*stack_a), 1, var);
		else
			ft_rra((*stack_a), 1, var);
	}
	else
	{
		if ((*stack_a)->content < pivot && (*stack_a)->next->content > pivot)
		{
			ft_sa((*stack_a), 1, var);
			ft_ra((*stack_a), 1, var);
		}
		else
		{
			ft_ra((*stack_a), 1, var);
			ft_sa((*stack_a), 1, var);
		}
	}
}

void	ft_sort_10(t_vars *var, t_lst **stack_a, t_lst **stack_b, int pivot)
{
	int	min;
	int	i;
	int	size;

	size = var->size;
	while (size > 3)
	{
		min = ft_get_min((*stack_a));
		i = ft_get_position((*stack_a), min);
		while ((*stack_a)->content != min)
		{
			if (i < size / 2)
				ft_ra((*stack_a), 1, var);
			else
				ft_rra((*stack_a), 1, var);
		}
		ft_pb(stack_a, stack_b, var);
		size--;
	}
	pivot = ft_get_pivot_10((*stack_a));
	ft_sort_3(stack_a, pivot, var);
	while ((*stack_b))
		ft_pa(stack_a, stack_b, var);
	ft_pa(stack_a, stack_b, var);
}
