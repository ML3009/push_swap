/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 07:52:47 by ml                #+#    #+#             */
/*   Updated: 2023/03/22 15:14:43 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_quicksort(t_vars *var, t_lst *stack_a, t_lst *stack_b, t_lst *stack_tmp)
{
    ft_get_index(stack_a);
    var->min = ft_get_min(stack_a);
    var->max = ft_get_max(stack_a);
    var->mid = ft_get_pivot(stack_a, (ft_size_lst(stack_a)/2));
    
    //flags
    ft_push_min(var, stack_a, stack_b);
    while(ft_sort_same(stack_a, stack_tmp, var) == 0)
    {
        if (ft_size_lst(stack_b) == 0)
            ft_quick_b(stack_a, stack_b, var);
        else
            ft_quick_a(stack_a, stack_b, stack_tmp, var);
    }
}

void    ft_push_min(t_vars *var, t_lst *stack_a, t_lst *stack_b)
{
    int i;

    i = 0;
    while(i < ft_size_lst(stack_a))
    {
        if (stack_a->content <= var->mid)
            ft_pb(&stack_a, &stack_b);
        else
        {
            if(ft_size_lst(stack_b) > 1 && stack_b->content < var->mid / 2)
                ft_rr(stack_a, stack_b);
            else
                ft_ra(stack_a, 1);
        }
        i++;
    }
    var->max = var->mid;
    var->mid = var->max / 2;
    var->min = ft_get_min(stack_a);
}

void    ft_quick_a(t_lst *stack_a, t_lst *stack_b, t_lst *stack_tmp, t_vars *var)
{
    int moves;
    int i;
    
    i = 0;
    moves = ft_size_lst(stack_b);
    while(ft_size_lst(stack_b) && i < moves)
    {
        if (stack_b->content == var->min)
            ft_put_min(stack_a, stack_b, var); // si valeur min est en haut ou en bas alors push a et reverse a
        else if (stack_b->content >= var->mid)
        {
            ft_pa(&stack_a, &stack_b);
        }
        else if (stack_b->content < var->mid)
            ft_rb(stack_b, 0);
        i++;
    }
    
}

void    ft_replace_min(t_lst *stack_a, t_lst *stack_b, t_vars *var)
{
    if (ft_size_lst(stack_b) > 0 && stack_b->content == var->min)
        ft_pa(&stack_a, &stack_b);
    else if (stack_a->content == var->min)
    {
        ft_ra(stack_a, 1);
            
    }
}