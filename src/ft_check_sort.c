/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:10:27 by mvautrot          #+#    #+#             */
/*   Updated: 2023/04/13 11:13:54 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_stack(t_vars *var, t_lst **stack_a,
			t_lst **stack_b, t_lst **stack_tmp)
{
	int	pivot;

	pivot = ft_get_pivot((*stack_tmp), (var->size / 2));
	if (ft_sort_same((*stack_a), (*stack_tmp), var) == 1)
	{
		ft_free_lst(*stack_tmp);
		ft_free_lst(*stack_a);
		exit(EXIT_SUCCESS);
	}
	if (var->size == 2 && (*stack_a)->content > (*stack_a)->next->content)
		ft_sa((*stack_a), 1, var);
	else if (var->size == 3)
		ft_sort_3((stack_a), pivot, var);
	else if (var->size <= 10)
		ft_sort_10(var, (stack_a), (stack_b), pivot);
	else
		ft_quicksort(var, stack_a, stack_b, stack_tmp);
}

int	ft_check_sorting(t_lst **stack)
{
	t_lst	*tmp;

	tmp = (*stack);
	while (tmp && tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
	tmp = tmp->next;
	}
	return (1);
}

int	ft_check_sorting_stack(t_lst **stack, int count)
{
	int	len;

	len = ft_size_lst(*stack);
	if (len != count)
		return (0);
	if (ft_check_sorting(stack) == 0)
		return (0);
	return (1);
}
