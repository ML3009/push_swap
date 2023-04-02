/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:24:08 by ml                #+#    #+#             */
/*   Updated: 2023/04/02 19:54:38 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_quicksort(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp)
{
    var->min = ft_get_min(*stack_tmp);
    var->max = ft_get_max(*stack_tmp);
    var->end = ft_get_max(*stack_tmp);
    var->mid_0 = ft_get_quick((*stack_tmp), var->size / 4);
    var->mid_1 =ft_get_quick((*stack_tmp), var->size / 2);
    var->mid_2 =ft_get_quick((*stack_tmp), ((var->size / 4 * 3)));
    ft_push_min(var, stack_a, stack_b, stack_tmp);
    var->mid = ft_get_quick((*stack_tmp), (((get_position((*stack_tmp), var->max) - (get_position((*stack_tmp), var->mid_2))) / 2 + (get_position((*stack_tmp), var->mid_2)))));
    var->min = var->mid_2;
    while(!check_sorting_a(stack_a, var->size))
    {

        ft_quick_b(stack_a, stack_b, stack_tmp, var);
        ft_quick_a(stack_a, stack_b, stack_tmp, var);
    }    
}

void    ft_push_min(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp)
{  
    if(ft_size_lst(*stack_a) == 0)
    {
        var->mid_0 = ft_get_quick((*stack_tmp), var->size / 4);
        var->mid_1 =ft_get_quick((*stack_tmp), var->size / 2);
        var->mid_2 =ft_get_quick((*stack_tmp), ((var->size / 4 * 3)));
        var->stop = ft_get_end(*stack_b);
        return;
    }
    else if(ft_size_lst(*stack_a) <= (var->size / 4))
        var->mid_0 = var->max;
    else if(ft_size_lst(*stack_a) <= (var->size / 2))
        var->mid_0 = var->mid_2;
    else if (ft_size_lst(*stack_a) <= (var->size / 4 * 3))
        var->mid_0 = var->mid_1;

    if ((*stack_a)->content <= var->mid_0)
            ft_pb(stack_a, stack_b);
    else
    {
        if(ft_size_lst((*stack_b)) > 1 && ((*stack_b)->content < var->mid_0 / 2))
            ft_rr((*stack_a), (*stack_b));
        else
            ft_ra((*stack_a), 1);
    } 
    ft_push_min(var, stack_a, stack_b, stack_tmp);
    
}

void    ft_quick_a(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{

   
 if(var->check == 1) /* le debut est trie donc je passe a la pile suivante avec un nv max, nv min et nv mid*/
 {  
    var->min = ft_get_quick((*stack_tmp), (ft_size_lst(*stack_b) / 2)); 
    if (var->max > var->mid_2)
        var->mid = var->mid_2;
    if (var->max < var->mid_2)
        var->mid = var->mid_1;
    if (var->max <= var->mid_1)
    {   var->mid = var->mid_0;
        var->min = ft_get_quick((*stack_tmp), (ft_size_lst(*stack_b) / 4));   
    } 
    if(var->max <= var->mid_0)
    {
        var->mid = ft_get_quick((*stack_tmp), (((get_position((*stack_tmp), var->max)/2))));
        var->min = ft_get_min(*stack_b);
        var->stop = ft_get_min(*stack_b);
    }
    while(ft_size_lst(*stack_b) > 0 && ft_last_lst(*stack_b)->content != var->stop)
    {
        if(ft_last_lst(*stack_b)->content != var->max)
            ft_rrb((*stack_b), 1);
        else if(ft_last_lst(*stack_b)->content == var->max)
            ft_replace_max(stack_a, stack_b, stack_tmp, var); 
    }
    if (var->stop > var->mid)
        var->mid = var->stop;
     
    if(ft_size_lst(*stack_b) > 0 && var->stop == var->max)
    {   
        ft_rrb((*stack_b), 1); 
        ft_pa(stack_a, stack_b);
        var->stop = ft_last_lst(*stack_b)->content;
       // exit(EXIT_SUCCESS);
    } 
    ft_quick_b(stack_a, stack_b, stack_tmp, var);
    //rappeler quick b.
 }
 else if (var->check == -1) /* pas triee en totalite donc on repush tout sauf le max(et tt ce qui est trie)*/
 {
    while(ft_last_lst(*stack_a)->content != var->end)
    {
        if(ft_last_lst(*stack_a)->content != var->max)
        {
            ft_rra((*stack_a), 1);
            ft_pb(stack_a, stack_b);
        }
              
        ft_replace_max(stack_a, stack_b, stack_tmp, var); 
    }
 }
  
}


void ft_quick_b(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{
    if (ft_size_lst(*stack_b) == 0)
        return;
    if (ft_size_lst(*stack_b) > 0 && var->max == var->mid)
    {
        var->check = 1; // la liste est triee jusqu a mid.
        if ((*stack_b)->content == var->max)
        {
            ft_pa(stack_a, stack_b);
            if ((*stack_b)->next != NULL)
                ft_search_next_max(stack_a, stack_b, stack_tmp, var);
         }
        return;
    }
    if ((*stack_b)->content == var->max || (*stack_b)->next->content == var->max || ft_last_lst(*stack_b)->content == var->max) 
        ft_replace_max(stack_a, stack_b, stack_tmp, var);   
    else if (ft_size_lst(*stack_a) > 0 && ((*stack_a)->content == var->max /*|| (*stack_a)->next->content == var->max)*/))
        ft_replace_max(stack_a, stack_b, stack_tmp, var);   
    else if (ft_size_lst(*stack_a) > 2 && ft_last_lst((*stack_a))->content == var->max)
        ft_replace_max(stack_a, stack_b, stack_tmp, var); 
    else if (ft_size_lst(*stack_a) == 2 && ft_last_lst((*stack_a))->content == var->max)
        ft_replace_max(stack_a, stack_b, stack_tmp, var); 
    else if (ft_size_lst(*stack_b) > 0 && (*stack_b)->content >= var->mid)
    {
        ft_pa(stack_a, stack_b);
        ft_ra(*stack_a, 1);
    }
    else if (ft_size_lst(*stack_b) > 2 &&(*stack_b)->content < var->mid && (*stack_b)->content > var->min)
        ft_rb((*stack_b), 0);
    else if (ft_size_lst(*stack_b) > 0 && ft_last_lst(*stack_b)->content >= var->mid)
    {
        ft_rrb((*stack_b), 1); 
        ft_pa(stack_a, stack_b);
        ft_ra(*stack_a, 1);
    }  
    else
        return;
        // la liste des max sera triee quand var-> max sera egal au var->mid_2 ; 
    ft_quick_b(stack_a, stack_b, stack_tmp, var);
}

void ft_replace_max(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{

 
    if (ft_size_lst(*stack_b) > 0 && var->max == var->mid && ft_last_lst((*stack_a))->content != var->max)
        return;
    if (ft_size_lst((*stack_b)) > 0 && (*stack_b)->content == var->max)
        ft_pa(stack_a, stack_b);
    else if ((*stack_b)->next != NULL && (*stack_b)->next->content == var->max)
        ft_sb((*stack_b), 1);   
    else if (ft_size_lst((*stack_b)) > 2 && ft_last_lst((*stack_b))->content == var->max)
        ft_rrb((*stack_b), 0); 
    else if (ft_size_lst((*stack_a)) > 2 && ft_last_lst((*stack_a))->content == var->max)
    {    ft_rra((*stack_a), 0);   
    }
    else if (ft_size_lst(*stack_a) == 2 && ft_last_lst((*stack_a))->content == var->max)
       ft_sa((*stack_a), 1);    
    else if ((*stack_a)->content == var->max)
    {
        var->check = -1;
        if ((*stack_b)->next != NULL)
            ft_search_next_max(stack_a, stack_b, stack_tmp, var);
        else
        {
            var->max = (*stack_b)->content;
            ft_pa(stack_a, stack_b);
            //exit(EXIT_SUCCESS);
            return;
        }
    }  
    else    
        return;
    ft_replace_max(stack_a, stack_b, stack_tmp, var);
}