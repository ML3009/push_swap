/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:05:02 by mvautrot          #+#    #+#             */
/*   Updated: 2023/04/03 09:53:00 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_pb(t_lst	**stack_a, t_lst **stack_b, t_vars *var)
{
	t_lst	*tmp;

	if ((*stack_a) != NULL)
	{
		tmp = ft_new_element ((*stack_a)->content);
		ft_add_front_lst((stack_b), tmp);
		tmp = (*stack_a)->next;
		//free;
		(*stack_a) = tmp;

	}
	var->count++;
	ft_putstr("pb\n");
}

void	ft_pa(t_lst **stack_a, t_lst ** stack_b, t_vars *var)
{
	t_lst	*tmp;

	if ((*stack_b) != NULL)
	{
		tmp = ft_new_element ((*stack_b)->content);
		ft_add_front_lst((stack_a), tmp);
		tmp = (*stack_b)->next;
		//free;
		(*stack_b) = tmp;

	}
	var->count++;
	ft_putstr("pa\n");
}
