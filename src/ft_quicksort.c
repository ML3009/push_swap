/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 07:52:47 by ml                #+#    #+#             */
/*   Updated: 2023/03/23 10:04:46 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_quicksort(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp)
{
    (void)stack_tmp;
    var->min = (*stack_tmp)->content;//ft_get_min((*stack_a));
    var->max = ft_get_max((*stack_a));
    var->mid = ft_get_pivot2((*stack_a), (ft_size_lst((*stack_a))/2));
    printf("mid : %i\n", var->mid);
    var->check = 0;
    //flags
    ft_push_min(var, stack_a, stack_b);
    while(ft_sort_same((*stack_a), (*stack_tmp), var) == 0)
    {
        if (ft_size_lst((*stack_b)) == 0)
            ft_quick_b(stack_a, stack_b, stack_tmp, var);
        else
            ft_quick_a(stack_a, stack_b, stack_tmp, var);
        //print_stack(stack_b, 0);
        //print_stack(stack_a, 1);
    }
}

void    ft_push_min(t_vars *var, t_lst **stack_a, t_lst **stack_b)
{
    int i;

    i = 0;
    while(i < var->size)
    {
        if ((*stack_a)->content <= var->mid)
            ft_pb(stack_a, stack_b);
        else
        {
            if(ft_size_lst((*stack_b)) > 1 && ((*stack_b)->content < var->mid / 2))
                ft_rr((*stack_a), (*stack_b));
            else
                ft_ra((*stack_a), 1);
        }
        i++;
    }
    var->max = var->mid;
    var->mid = ft_get_pivot2(*stack_a, (ft_size_lst((*stack_a))/2));
}

void    ft_quick_a(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{
    int moves;
    int i;
    i = 0;
    moves = ft_size_lst((*stack_b));
    print_stack(stack_a, 1);
    print_stack(stack_b, 0);
    while(ft_size_lst((*stack_b)) && i < moves)
    {
        printf("ICI?");
        printf("var->min : %i\n", var->min);
        if ((*stack_b)->content == var->min)
            ft_replace_min(stack_a, stack_b, stack_tmp, var); // si valeur min est en haut ou en bas alors push a et reverse a
        else if ((*stack_b)->content >= var->mid)
        {
            printf("ICI?");
            ft_pa(stack_a, stack_b);
        }
        else if ((*stack_b)->content < var->mid)
            ft_rb((*stack_b), 0);
        i++;
    }
    var->max = var->mid;
    var->mid = ft_get_pivot2(*stack_a, (ft_size_lst((*stack_a))/2));
}

void    ft_replace_min(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{
    if (ft_size_lst((*stack_b)) > 0 && (*stack_b)->content == var->min)
        ft_pa(stack_a, stack_b);
    else if ((*stack_a)->content == var->min)
    {
        var->check = 1;
        ft_ra((*stack_a), 1);
        (*stack_tmp) = (*stack_tmp)->next;
        var->min = (*stack_tmp)->content;
        //var->min++;
        printf("var->min : %i\n", var->min);
            
    }
    else if (ft_size_lst((*stack_b)) > 2 && ft_last_lst((*stack_b))->content == var->min)
        ft_rrb((*stack_b), 0);
    else if ((*stack_a)->next->content == var->min)
    {
        ft_sa((*stack_a), 1);
    }
    else if (ft_size_lst((*stack_a)) > 1 && (*stack_a)->next->content == var->min 
        && (*stack_b)->next->content == var->min + 1)
        ft_ss((*stack_a),(*stack_b));
    else    
        return;
    ft_replace_min(stack_a, stack_b, stack_tmp, var);
    
}

void    ft_quick_b(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{
    int check_tmp;

    check_tmp = var->check;
    
    if(var->check != 0)
    {
        while(var->check == check_tmp)
        {
            if ((*stack_a)->content != var->min)
                ft_pb(stack_a, stack_b);
            ft_replace_min(stack_a, stack_b, stack_tmp, var);
        }
    }
    else if (var->check == 0)
    {
        while(var->check != 1)
        {
            if ((*stack_a)->content != var->min)
                ft_pb(stack_a, stack_b);
            ft_replace_min(stack_a, stack_b, stack_tmp, var);
        }
    }
    if (ft_size_lst((*stack_b)))
        var->max = (ft_get_max(*stack_b));
    var->mid = ft_get_pivot2(*stack_b, (ft_size_lst((*stack_b))/2));
}