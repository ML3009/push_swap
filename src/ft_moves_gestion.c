/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_gestion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:10:27 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/22 17:39:32 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_stack(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp)
{
	int	pivot;
	
	pivot = ft_get_pivot((*stack_tmp), (var->size / 2));
	if (ft_sort_same((*stack_a), (*stack_tmp), var) == 1)
		exit(EXIT_SUCCESS);
	if (var->size == 3)
	{
		ft_sort_3((*stack_a), (*stack_b), pivot);
	}
	else if (var->size <= 10)
	{
		ft_sort_10(var, (*stack_a), (*stack_b), pivot);
	}
	else
	{
		ft_quicksort(var, stack_a, stack_b, stack_tmp); 
	}
}
