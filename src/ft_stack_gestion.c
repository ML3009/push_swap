/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_gestion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:10:27 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/10 11:54:25 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stack_init(t_vars *var, t_lst **stack_a, t_lst **stack_b)
{
	int	i;
	int	temp;
	t_lst *tmp;
	(void)stack_b;

	i = 0;
	while (i < var->size)
	{
		temp = ft_atoi(var->tmp_lst[i]);
		tmp = ft_new_element(temp);
		ft_add_back_lst(stack_a, tmp);
		i++;
	}
	//i = 0;
	//while (i < var->size)
	//{
	//	temp = ft_atoi(var->tmp_lst[i]);
	//	tmp = ft_new_element(temp);
	//	ft_add_back_lst(stack_b, tmp);
	//	i++;
	//}
}

void	ft_stack_move(t_lst *stack_a, t_lst *stack_b)
{

	ft_swap_a(stack_a, 1);
	ft_swap_b(stack_b, 1);
	ft_swap_a_b(stack_a, stack_b);
	ft_push_b(&stack_a, &stack_b);
	ft_push_a(&stack_a, &stack_b);
}
