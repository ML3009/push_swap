/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:05:02 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/09 20:21:47 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void	ft_push_a(t_lst	*stack_a, t_lst *stack_b, int i)
{
	int	tmp;
	t_lst *save_a;
	t_lst *save_b;

	save_a = stack_a;
	save_b = stack_b;

	if (stack_a->next && stack_b->next)
	{
		tmp = stack_a->content;
		save_a = stack_a->next;
		ft_add_front_lst(tmp, stack_b);
		//value a stock tmp;
		//content->next est egal au debut de la pile.
		//addfront pile b
	}

}

void	ft_push_b(t_lst *stack_a, t_lst *stack_b, int i)
{

}
