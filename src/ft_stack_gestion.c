/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_gestion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:10:27 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/10 18:18:03 by mvautrot         ###   ########.fr       */
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
}

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
	if (var->size == 3)
	{
		if ()
	}
}
