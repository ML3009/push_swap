/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:10:47 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/10 12:41:19 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_lst *stack_a, int i)
{
	t_lst *tmp;
	int	save;


	if (stack_a && stack_a->next)
	{
		save = stack_a->content;
		tmp = stack_a;
		while (stack_a->next)
		{
			stack_a->content = stack_a->next->content;
			stack_a = stack_a->next;
		}
		stack_a->content = save;
		stack_a = tmp;
		if (i == 1)
			ft_putstr("ra\n");
	}
}

void	ft_rb(t_lst *stack_b, int i)
{
	t_lst *tmp;
	int	save;


	if (stack_b && stack_b->next)
	{
		save = stack_b->content;
		tmp = stack_b;
		while (stack_b->next)
		{
			stack_b->content = stack_b->next->content;
			stack_b = stack_b->next;
		}
		stack_b->content = save;
		stack_b = tmp;
		if (i == 1)
			ft_putstr("rb\n");
	}
}

void	ft_rr(t_lst *stack_a, t_lst *stack_b)
{
	if ((stack_a && stack_a->next) && (stack_b && stack_b->next))
	{
		ft_ra(stack_a, 0);
		ft_rb(stack_b, 0);
		ft_putstr("rr\n");
	}
}
