/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_gestion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:10:27 by mvautrot          #+#    #+#             */
/*   Updated: 2023/04/05 11:34:56 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stack_init(t_vars *var, t_lst **stack_a, t_lst **stack_tmp)
{
	int	i;
	int	temp;
	t_lst *tmp;

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
	free(var->tmp_lst);
}

void	ft_check_stack(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp)
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
		ft_sort_3((stack_a), (stack_b), pivot,var);
	else if (var->size <= 10)
		ft_sort_10(var, (stack_a), (stack_b), pivot);
	else
		ft_quicksort(var, stack_a, stack_b, stack_tmp);
}



