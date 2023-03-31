/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 07:52:47 by ml                #+#    #+#             */
/*   Updated: 2023/03/30 19:24:45 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_quicksort(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp)
{
    var->min = ft_get_min((*stack_a));
    var->max = ft_get_max((*stack_a));
    var->mid = ft_get_pivot_test((*stack_tmp), ft_size_lst(*stack_tmp) / 2);
    var->check = 0;
    ft_push_min(var, stack_a, stack_b, stack_tmp);
    while(!check_sorting_a(stack_a, var->size))
    {
        if (ft_size_lst((*stack_b)) == 0)
        {
            ft_quick_b(stack_a, stack_b, stack_tmp, var);
        }
        else
            ft_quick_a(stack_a, stack_b, stack_tmp, var);
    }
    print_stack(stack_a, 1);
    print_stack(stack_b, 0);
    printf("var->min :%i \n", var->min);
   // print_stack(stack_a, 1);
   // print_stack(stack_b, 1);
}



void    ft_push_min(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp)
{
   // int i;

   // i = 0;
    //while(i < ft_size_lst(*stack_a))
   // {
        if(ft_size_lst(*stack_a) < var->size / 2)
        {
            var->max = var->mid;
            var->mid = ft_get_pivot_test((*stack_tmp), (((get_position((*stack_tmp), var->max) - (get_position((*stack_tmp), var->min))) / 2 + (get_position((*stack_tmp), var->min)))));
            var->check = 1 ; // var_check = 1
            return;
        }
        if ((*stack_a)->content <= var->mid)
            ft_pb(stack_a, stack_b);
        else
        {
            if(ft_size_lst((*stack_b)) > 1 && ((*stack_b)->content < var->mid / 2))
                ft_rr((*stack_a), (*stack_b));
            else
                ft_ra((*stack_a), 1);
        }
      //  i++;
   // }
   ft_push_min(var, stack_a, stack_b, stack_tmp);
   //var->max = var->mid;
   // var->mid = ft_get_pivot_test((*stack_tmp), (((get_position((*stack_tmp), var->max) - (get_position((*stack_tmp), var->min))) / 2 + (get_position((*stack_tmp), var->min)))));
}

void    ft_replace_min(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{
        if(ft_size_lst(*stack_b) == 0 && (*stack_a)->content != var->min)
            return;
        if (ft_size_lst((*stack_b)) > 0 && (*stack_b)->content == var->min)
            ft_pa(stack_a, stack_b);
        else if ((*stack_a)->content == var->min)
        {
            var->check = -1;
            var->end = (*stack_a)->content;
            ft_ra((*stack_a), 1);  
            if ((*stack_tmp)->next != NULL)
            {
                var->min = (*stack_tmp)->next->content;
                (*stack_tmp) = (*stack_tmp)->next;
            }
        }
        else if (ft_size_lst((*stack_b)) > 2 && ft_last_lst((*stack_b))->content == var->min)
            ft_rrb((*stack_b), 0);
        else if (ft_size_lst((*stack_a)) > 1 && (*stack_a)->next->content == var->min)
        {
            ft_sa((*stack_a), 1);
        }
        else if (ft_size_lst((*stack_a)) > 1 && (*stack_b)->next != NULL && (*stack_a)->next->content == var->min 
            && (*stack_b)->next->content == (*stack_tmp)->next->content/*ft_get_min(*stack_b)*/)
        {
            ft_ss((*stack_a),(*stack_b));
        }
        else 
        {
            var->check = 0;
            return;
        }
        ft_replace_min(stack_a, stack_b, stack_tmp, var);
}

void    ft_quick_a(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{
   // int moves;
    //int i;
    //i = 0;
  //  moves = ft_size_lst((*stack_b));
  //  while(ft_size_lst((*stack_b)) && i < moves)
  //  {

    printf("var->mid : %i\n", var->mid);
        if(ft_size_lst(*stack_b) == 0)
        {
          //  var->max = var->mid;
          //  if (var->max < var->min)
            var->max = ft_get_max(*stack_a);//if (ft_size_lst(*stack_b) > 0)
            var->mid =ft_get_pivot_test((*stack_tmp), (((get_position((*stack_tmp), var->max) - (get_position((*stack_tmp), var->min))) / 2 + (get_position((*stack_tmp), var->min)))));
            printf("VQR MID %i\n", var->mid);
            var->check++; // var_check = 0 ou 1; 
            return;
        }
        if ((*stack_b)->content == var->min)
           ft_replace_min(stack_a, stack_b, stack_tmp, var); 
        else if (ft_size_lst(*stack_b) > 0 && (*stack_b)->content >= var->mid)
        {
            ft_pa(stack_a, stack_b);
        }
        else if (ft_size_lst(*stack_b) > 1 &&(*stack_b)->content < var->mid)
            ft_rb((*stack_b), 0);
   //     i++;
  //  }
    var->check = 1;
    ft_quick_a(stack_a, stack_b, stack_tmp, var);
}

void    ft_quick_b(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{
    int min = ft_get_min(*stack_a);
    if(ft_size_lst(*stack_a) == 3)
    {
        if((*stack_a)->content > (*stack_a)->next->content
            && (*stack_a)->content > ft_last_lst((*stack_a))->content)
            ft_ra((*stack_a), 1);
        if((*stack_a)->next->content > (*stack_a)->content
            && (*stack_a)->next->content > ft_last_lst((*stack_a))->content)
            ft_sa((*stack_a), 1);
        if(ft_last_lst((*stack_a))->content > (*stack_a)->content
            && ft_last_lst((*stack_a))->content > (*stack_a)->next->content)
            ft_rra((*stack_a), 1);
    }
    while((*stack_a)->content != min)
    {
        if ((*stack_a)->content == var->min)
            ft_replace_min(stack_a, stack_b, stack_tmp, var);
        else if ((*stack_a)->content <= var->mid)
        {
            ft_pb(stack_a, stack_b);
            if (var->check == 1 && (*stack_b)->content <= var->mid)
                ft_rb((*stack_b), 1);
        }
        else
        {
            ft_ra((*stack_a), 1);
            if (var->check == 1 && (*stack_b)->content <= var->mid)
                ft_rb((*stack_b), 1);
        }
    }
    printf("vqr min %i\n", var->min);
    //exit(EXIT_SUCCESS);
    while((*stack_a)->content != var->end)
        ft_rra((*stack_a), 1);
    print_stack(stack_a, 1);
    print_stack(stack_b, 0);
    var->max = var->mid;
    if (ft_size_lst(*stack_b) < 2)
        ft_quick_b(stack_a, stack_b, stack_tmp, var);
    var->mid =ft_get_pivot_test((*stack_tmp), (((get_position((*stack_tmp), var->max) - (get_position((*stack_tmp), var->min))) / 2 + (get_position((*stack_tmp), var->min)))));
    //var->check++;
    ft_quick_a(stack_a, stack_b, stack_tmp, var);
}

/*void    ft_quick_b(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{
   int check_tmp;
   int min = ft_get_min(*stack_a);
    check_tmp = var->check;
    printf("var->min : %i\n", var->min);

            printf("var->check : %i\n", var->check);
    
    if (var->check >= 0)
    {
        while(var->check >= 0 && (*stack_a)->content != min)
        {
            if ((*stack_a)->content != var->min)
                ft_pb(stack_a, stack_b);
            ft_replace_min(stack_a, stack_b, stack_tmp, var);
            
            printf("coucou != 0 \n");
            printf("var->check : %i\n", var->check);
             printf("check_tmp : %i\n", check_tmp);
              print_stack(stack_a, 1);
            print_stack(stack_b, 0);
            printf("var->min :%i \n", var->min);
        }   
    }
    if(var->check == -1)
    {
        while(var->check != 0 && (*stack_a)->content != min)
        {
            if ((*stack_a)->content != var->min)
                ft_pb(stack_a, stack_b);
            ft_replace_min(stack_a, stack_b, stack_tmp, var);
            //var->check++;
            printf("coucou 0 \n");
            printf("var->check : %i\n", var->check);
        }
    }*/
 
   
   /* int min = ft_get_min(*stack_a);
    //var->max = ft_get_max(*stack_a);
    //var->mid =ft_get_pivot_test((*stack_tmp), (((get_position((*stack_tmp), var->max) - (get_position((*stack_tmp), var->min))) / 2 + (get_position((*stack_tmp), var->min)))));
    while((*stack_a)->content != min)
    {
        if ((*stack_a)->content == var->min)
        { 
            ft_ra((*stack_a), 1);
            if ((*stack_tmp)->next != NULL)
            {
                var->min = (*stack_tmp)->next->content;
                (*stack_tmp) = (*stack_tmp)->next;
            }
            if (check_sorting_a(stack_a, var->size) == 1)
                return ;
        }
        else if ((*stack_a)->content <= var->mid)
        {
            ft_pb(stack_a, stack_b);
        }
        else if ((*stack_a)->content > var->mid) //&& ft_size_lst(*stack_b) > 1)
        { 
                ft_pb(stack_a, stack_b);
                ft_rb(*stack_b, 1);
        }
    }
    //var->max = var->mid;
    var->mid =ft_get_pivot_test((*stack_tmp), (((get_position((*stack_tmp), var->max) - (get_position((*stack_tmp), var->min))) / 2 + (get_position((*stack_tmp), var->min)))));
    var->check++;
}*/
