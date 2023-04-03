/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:24:08 by ml                #+#    #+#             */
/*   Updated: 2023/04/03 17:15:53 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_quicksort(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp)
{
    var->quick = 1;
    ft_push_min(var, stack_a, stack_b, stack_tmp, var->quick);
    ft_quick_a(stack_a, stack_b, stack_tmp, var);
}

void    ft_push_min(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, int n)
{
    int i;

    i = 0;
    while (i < var->size / 10)
    {
        if ((*stack_a)->content <= ft_get_quick((*stack_tmp), var->size / 10 * n))
        {
            ft_pb(stack_a, stack_b,var);
            i++;
        }
        else
            ft_ra((*stack_a), 1,var);
    }
    if(ft_size_lst(*stack_a) <= var->size / 10)
    {
        while ((*stack_a)->next != NULL)
            ft_pb(stack_a, stack_b,var);
        ft_pb(stack_a, stack_b,var);
        return;
    }
    ft_push_min(var, stack_a, stack_b, stack_tmp, n + 1);
}

void    ft_quick_a(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{
    (void)stack_tmp;
    while (ft_size_lst(*stack_b) > 1)
    {
        var->max = ft_get_max(*stack_b);
        if (get_position((*stack_b), var->max) <= var->size / 10)
        {
            while ((*stack_b)->content != var->max)
                ft_rb((*stack_b), 1, var);
        }
        else
        {
            while((*stack_b)->content != var->max)
                ft_rrb((*stack_b), 1, var);
        }
        ft_pa(stack_a, stack_b, var);
    }
    ft_pa(stack_a, stack_b, var);
}

