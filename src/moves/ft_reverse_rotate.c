/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:43:59 by mvautrot          #+#    #+#             */
/*   Updated: 2023/04/05 09:10:35 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_rra(t_lst *stack_a, int i, t_vars *var)
{
	t_lst	*tmp;
	int	save;
	int save_one;

	if (stack_a && stack_a->next)
	{
		tmp = stack_a;
		stack_a = ft_last_lst(stack_a);
		save = stack_a->content; 
		stack_a = tmp;
		while(stack_a->next)
		{
			save_one = stack_a->content;
			stack_a->content = save;
			save = save_one;
			stack_a = stack_a->next;
		}
		stack_a->content = save;
		stack_a = tmp;
		if (i == 1)
		{
			ft_putstr("rra\n");
			var->count++;
		}
	}
}

void	ft_rrb(t_lst *stack_b, int i, t_vars *var)
{
	t_lst	*tmp;
	int	save;
	int save_one;

	if (stack_b && stack_b->next)
	{
		tmp = stack_b;
		stack_b = ft_last_lst(stack_b);
		save = stack_b->content;
		stack_b = tmp;
		while(stack_b->next)
		{
			save_one = stack_b->content;
			stack_b->content = save;
			save = save_one;
			stack_b = stack_b->next;
		}
		stack_b->content = save;
		stack_b = tmp;
		if (i == 1)
		{
			ft_putstr("rrb\n");
			var->count++;
		}
	}
}


void	ft_rrr(t_lst *stack_a, t_lst *stack_b, t_vars *var)
{
	if ((stack_a && stack_a->next) && (stack_b && stack_b->next))
	{
		ft_rra(stack_a, 0,var);
		ft_rrb(stack_b, 0,var);
		ft_putstr("rrr\n");
		var->count++;
	}

}
