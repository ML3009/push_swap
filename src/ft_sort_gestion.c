/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_gestion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:32:38 by ml                #+#    #+#             */
/*   Updated: 2023/03/24 15:21:47 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_list(t_lst *stack_tmp)
{
	int	swap;
	t_lst	*tmp;

	tmp = stack_tmp;
	while(stack_tmp->next)
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
	int i;

	tmp_a = stack_a;
	tmp = stack_tmp;
	i = 0;
	while (i < var->size)
	{
		if (stack_a->content != stack_tmp->content)
		{
			stack_a = tmp_a;
			stack_tmp = tmp;
			return(0);
		}
		stack_a = stack_a->next;
		stack_tmp = stack_tmp->next;
		i++;
	}
	return(1);
}

void	ft_sort_3(t_lst	*stack_a, t_lst *stack_b, int pivot)
{
	t_lst	*tmp;
	(void)stack_b;

	tmp = stack_a;
	if (stack_a->content < pivot && stack_a->next->content == pivot)
		return;
	if(stack_a->content > pivot && stack_a->next->content < pivot)
		ft_ra(stack_a, 1);
	else if (stack_a->content == pivot)
	{
		if(stack_a->next->content < pivot)
			ft_sa(stack_a, 1);
		else
			ft_rra(stack_a, 1);
	}
	else
	{
		if (stack_a->content < pivot && stack_a->next->content > pivot)
		{
			ft_ra(stack_a, 1);
			ft_sa(stack_a, 1);
		}
	}
	stack_a = tmp;
}

void	ft_sort_10(t_vars *var, t_lst *stack_a, t_lst *stack_b, int pivot)
{
	int	min;
	int size = var->size;

	while (size > 3)
	{
		min = ft_get_min(stack_a);
		while(stack_a->content != min)
			ft_ra(stack_a, 1);
		ft_pb(&stack_a, &stack_b);
		size--;
	}
	pivot = ft_get_new_pivot(stack_a);	
	ft_sort_3(stack_a,stack_b,pivot);
	while((stack_b))
		ft_pa(&stack_a, &stack_b);
	ft_pa(&stack_a, &stack_b);
}
