/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:05:02 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/10 10:55:25 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void	ft_push_a(t_lst	*stack_a, t_lst *stack_b, int i)
{
	t_lst	*tmp;

	if (stack_a->next /*&& stack_b->next*/)
	{
		tmp = ft_new_element (stack_a->content);
		ft_add_front_lst(&stack_b, tmp);
		tmp = stack_a->next;
		//free;
		stack_a = tmp;
	}
	if (i == 1)
		ft_putstr("pa\n");

	print_stack(&stack_a);
	print_stack(&stack_b);
}

//void	ft_push_b(t_lst *stack_a, t_lst *stack_b, int i)
//{
//
//}
