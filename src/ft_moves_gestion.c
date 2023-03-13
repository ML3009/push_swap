/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_gestion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:10:27 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/13 15:51:45 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	else 
	{
		ft_sort_pivot(var, (*stack_a), (*stack_b), pivot);
	}
}
