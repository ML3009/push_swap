/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:51:46 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/09 20:07:15 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stack_move(t_lst *stack_a, t_lst *stack_b)
{

	ft_swap_a(stack_a, 1);
	ft_swap_b(stack_b, 1);
	ft_swap_a_b(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
}

void	ft_swap_a(t_lst *stack_a, int i)
{
	int	tmp;
	t_lst	*save;

	save = stack_a;
	if (stack_a->next)
	{
		tmp = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = tmp;
		stack_a = save;
		if (i == 1)
			ft_putstr("sa\n");
	}
}

void	ft_swap_b(t_lst *stack_b, int i)
{
	int	tmp;
	t_lst	*save;

	save = stack_b;
	if (stack_b->next)
	{
		tmp = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = tmp;
		stack_b = save;
		if (i == 1)
			ft_putstr("sb\n");
	}
}

void	ft_swap_a_b(t_lst *stack_a, t_lst *stack_b)
{
	if (stack_a->next && stack_b->next)
	{
		ft_swap_a(stack_a, 0);
		ft_swap_b(stack_b, 0);
		ft_putstr("ss\n");
	}
}
