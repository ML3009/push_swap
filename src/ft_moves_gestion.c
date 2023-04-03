/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_gestion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:10:27 by mvautrot          #+#    #+#             */
/*   Updated: 2023/04/03 10:03:22 by mvautrot         ###   ########.fr       */
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
		ft_sort_3((*stack_a), (*stack_b), pivot,var);
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



int	ft_get_next_max(t_lst *stack, int size)
{
	int	i;
	t_lst *tmp;

	tmp = stack;
	i = 0;
	while (tmp->next != NULL && i < size - 1)
	{
		tmp = tmp->next;
		i++;
	}
	return(tmp->content);
}

int	ft_get_min_10(t_lst *stack, int size)
{
	int	i;
	t_lst *tmp;

	tmp = stack;
	i = 0;
	while (tmp->next != NULL && i < size - (size - 10))
	{
		tmp = tmp->next;
		i++;
	}
	return(tmp->content);
}

