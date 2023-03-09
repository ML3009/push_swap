/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:05:02 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/09 20:36:14 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void	ft_push_a(t_lst	*stack_a, t_lst *stack_b, int i)
{
	t_lst	*tmp;
	t_lst *save_a;
	t_lst *save_b;

	save_a = stack_a;
	save_b = stack_b;

	if (stack_a->next && stack_b->next)
	{
		tmp = stack_a->content;
		save_a = stack_a->next;
		ft_add_front_lst(&stack_b, tmp);
		//value a stock tmp;
		//content->next est egal au debut de la pile.
		//addfront pile b
	}
	if (i == 1)
		ft_putstr("pa");

}

//void	ft_push_b(t_lst *stack_a, t_lst *stack_b, int i)
//{
//
//}
