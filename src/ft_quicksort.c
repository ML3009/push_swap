/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 07:52:47 by ml                #+#    #+#             */
/*   Updated: 2023/03/24 16:22:59 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_quicksort(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp)
{
    var->min = ft_get_min((*stack_a));
    var->max = ft_get_max((*stack_a));
    var->mid = ft_get_pivot((*stack_a), ft_size_lst(*stack_a) / 2);
    ft_push_min(var, stack_a, stack_b);
    while(!check_sorting_a(stack_a, var->size))
    {
        if (ft_size_lst((*stack_b)) == 0)
        {
           ft_quick_b(stack_a, stack_b, stack_tmp, var);

        }
        else
            ft_quick_a(stack_a, stack_b, stack_tmp, var);
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
}

void    ft_quick_a(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{
    int moves;
    int i;
    i = 0;
    moves = ft_size_lst((*stack_b));
    var->end = ft_get_pivot((*stack_b), ft_size_lst(*stack_b)/2);
    while(ft_size_lst((*stack_b)) && i < moves)
    {
        if ((*stack_b)->content == var->min)
           ft_replace_min(stack_a, stack_b, stack_tmp, var); // si valeur min est en haut ou en bas alors push a et reverse a
        if ((*stack_b)->content >= var->end)
        {
            ft_pa(stack_a, stack_b);
            if (ft_size_lst(*stack_b) < 2)
                return;
            printf("COUCOU?22\n");
        }
        else if ((*stack_b)->content < var->end && ft_size_lst(*stack_b) > 1)
            ft_rb((*stack_b), 0);
        i++;
    }
    if (ft_size_lst(*stack_a) > 1)
        var->mid = ft_get_pivot(*stack_a, (ft_size_lst((*stack_a))/2));
}

void    ft_replace_min(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{
    (void)stack_tmp;
    while (ft_last_lst(*stack_a)->content != var->min && ft_size_lst(*stack_a) && ft_size_lst(*stack_b))
    {
        if (ft_size_lst((*stack_b)) > 0 && (*stack_b)->content == var->min)
        {
            ft_pa(stack_a, stack_b);
            if (ft_size_lst(*stack_b) < 2)
                return;
            printf("COUCOU?\n");
        }
        else if ((*stack_a)->content == var->min)
        {
            ft_ra((*stack_a), 1);    
        }
        else if (ft_size_lst((*stack_b)) > 2 && ft_last_lst((*stack_b))->content == var->min)
            ft_rrb((*stack_b), 0);
        else if ((*stack_a)->next->content == var->min)
        {
            ft_sa((*stack_a), 1);
        }
        //else if (ft_size_lst((*stack_a)) > 1 && (*stack_a)->next->content == var->min 
        //    && (*stack_b)->next->content == var->min)
        //ft_ss((*stack_a),(*stack_b));
        else    
            return;
    }
}

void    ft_quick_b(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{
    (void)stack_tmp;
    var->min = ft_get_min(*stack_a);
    while((*stack_a)->content != var->min)
    {
            ft_pb(stack_a, stack_b);  
    }
    var->min = ft_get_min(*stack_b);
    if (ft_size_lst(*stack_b) > 3)
        ft_replace_min(stack_a, stack_b, stack_tmp, var);
    else
    {
        while(ft_size_lst(*stack_b))
        {
            var->min = ft_get_min(*stack_b);
            if (ft_size_lst((*stack_b)) > 0 && (*stack_b)->content == var->min)
                ft_pa(stack_a, stack_b);
            else if (ft_size_lst((*stack_b)) > 2 && ft_last_lst((*stack_b))->content == var->min)
                ft_rrb((*stack_b), 0);
            else if (ft_size_lst((*stack_b)) > 1 && (*stack_b)->next->content == var->min)
                ft_sb((*stack_b), 1);
            ft_pa(stack_a, stack_b);
            ft_ra((*stack_a), 1);
        }
        print_stack(stack_b, 0);
        ft_get_index(*stack_a);
        print_stack(stack_a, 1);
        printf("CPICPOU\n");
        //exit(EXIT_SUCCESS);
     //   ft_sort_3((*stack_b), (*stack_a), ft_get_new_pivot(*stack_b));
            
    }
   // if (ft_size_lst(*stack_a) <= 4)
        
    //var->min = ft_get_min(*stack_a);
   // if ((*stack_a)->content > var->mid)
     //   ft_pb(stack_a, stack_b);
    //else
      //   ft_ra((*stack_a), 1);  
    print_stack(stack_b, 0);
    print_stack(stack_a, 1);
    //ft_push_min(var, stack_a, stack_b);
    //ft_quick_b(stack_a, stack_b, stack_tmp, var);
}

int	check_sorting(t_lst **stack1)
{
	t_lst	*tmp;

	tmp = (*stack1);
	ft_get_index(tmp);
    print_stack(&tmp, 1);
    while (tmp && tmp->next)
	{
        if (tmp->content > tmp->next->content)
        {
            return (0);
        }
        tmp = tmp->next;
	}
    printf("ICI STASH NONONONON?");
	return (1);
    printf("ICI STASH ?");
}

int	check_sorting_a(t_lst **stack1, int count)
{
	int	len;

	len = ft_size_lst(*stack1);
    printf ("len : %i\n", len);
     printf ("count : %i\n", count);
	if (len != count)
    {
		printf("lskjflkewjf\n");
        return (0);
    }
    if (check_sorting(stack1) == 0)
		return (0);
	return (1);
}