/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_gestion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:10:27 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/13 13:30:22 by ml               ###   ########.fr       */
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

void	ft_stack_move(t_lst *stack_a, t_lst *stack_b)
{
	ft_sa(stack_a, 1);
	ft_sb(stack_b, 1);
	ft_ss(stack_a, stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pa(&stack_a, &stack_b);
	ft_ra(stack_a, 1);
	ft_rb(stack_b, 1);
	ft_rr(stack_a, stack_b);
	ft_rra(stack_a, 1);
	ft_rrb(stack_b, 1);
	ft_rrr(stack_a, stack_b);
}

void	ft_check_list(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp)
{
	int	pivot;

	
	pivot = ft_get_pivot((*stack_tmp), (var->size / 2));
	if (ft_sort_same((*stack_a), (*stack_tmp), var) == 1)
		exit(EXIT_SUCCESS);
	if (var->size == 3)
	{
		ft_sort_3((*stack_a), (*stack_b), pivot);
	}
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
	
	tmp = stack_a;
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
			ft_pb(&stack_a, &stack_b);
			ft_sa(stack_a, 1);
			ft_pa(&stack_a, &stack_b);
		}
		else
		{
			ft_ra(stack_a, 1);
			ft_sa(stack_a, 1);
		}
	}
	stack_a = tmp;
}
