/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_gestion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:32:38 by ml                #+#    #+#             */
/*   Updated: 2023/03/13 18:09:31 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_list(t_lst *stack_tmp)
{
	int	swap;
	t_lst	*tmp;

	tmp = stack_tmp;
	while(stack_tmp->next)
	{
		if (stack_tmp->content > stack_tmp->next->content)
		{
			swap = stack_tmp->content;
			stack_tmp->content = stack_tmp->next->content;
			stack_tmp->next->content = swap;
			stack_tmp = tmp;
		}
		else
			stack_tmp = stack_tmp->next;
	}
	stack_tmp = tmp;
}

int	ft_sort_same(t_lst *stack_a, t_lst *stack_tmp, t_vars *var)
{
	t_lst	*tmp_a;
	t_lst	*tmp;
	int i;
	
	tmp_a = stack_a;
	tmp = stack_tmp;
	i = 0;
	while (i < var->size)
	{
		if (stack_a->content != stack_tmp->content)
		{
			stack_a = tmp_a;
			stack_tmp = tmp;
			return(0);
		}
		stack_a = stack_a->next;
		stack_tmp = stack_tmp->next;
		i++;
	}
	return(1);
}

void	ft_sort_3(t_lst	*stack_a, t_lst *stack_b, int pivot)
{
	t_lst	*tmp;
	
	tmp = stack_a;
	if(stack_a->content > pivot && stack_a->next->content < pivot)
		ft_ra(stack_a, 1);
	else if (stack_a->content == pivot)
	{
		if(stack_a->next->content < pivot)
			ft_sa(stack_a, 1);
		else 
			ft_rra(stack_a, 1);
	}
	else
	{
		if (stack_a->content < pivot && stack_a->next->content > pivot)
		{
			ft_pb(&stack_a, &stack_b);
			ft_sa(stack_a, 1);
			ft_pa(&stack_a, &stack_b);
		}
		else
		{
			ft_ra(stack_a, 1);
			ft_sa(stack_a, 1);
		}
	}
	stack_a = tmp;
}

void	ft_sort_pivot(t_vars *var, t_lst *stack_a, t_lst *stack_b, int pivot)
{
	//t_lst	*tmp_a;
	//t_lst	*tmp_b;
	int	i;
	int	a;
	int	b;
	int pivot_a;
	int	pivot_b;
	
	//tmp_a = (*stack_a);
	//tmp_b = stack_b;
	i = 0;
	pivot_a = 0;
	pivot_b = 0;
	a = 0;
	b = 0;

	printf("pivot : [%i]\n", pivot);
	while (i < var->size)
	{
		if(stack_a->content < pivot)
		{	
			ft_pb(&stack_a, &stack_b);
			b++;
		}
		else
		{
			ft_ra(stack_a, 1);
			a++;
		}
		i++;
	}
	ft_sort_3(stack_a, stack_b, stack_a->content);
	i = 0;
	while(i < 3)
	{
		ft_pb(&stack_a, &stack_b);
		ft_rb(stack_b, 1);
		i++;
	}
	i = 0;
	while(i < 3)
	{
		ft_pa(&stack_a, &stack_b);
		i++;
	}
	
	//tmp_a = stack_a;
	//tmp_b = stack_b;
	
	/*pivot_a = tmp_a->content;
	pivot_b = tmp_b->content;
	i = 0;
	while(i < a)
	{
		if(stack_a->content < pivot_a)
			ft_ra(stack_a, 1);
		else 
			ft_pb(&stack_a, &stack_b);
		i++;
	}

	pivot_a = stack_a->content;*/

	print_stack(&stack_b, 0);
	print_stack(&stack_a, 1);
	i = 0;
	/*while (i < a)
	{
		ft_pb(&stack_a, &stack_b);
		ft_rb(stack_b, 1);
		i++;
	}*/
	printf("pivot_a : [%i]\n", pivot_a);
	printf("pivot_b : [%i]\n", pivot_b);
	
	
	/*i = 0;
	while (stack_b->next)
	{
		ft_pa(&stack_a, &stack_b);
		i++;
	}
	printf ("i : %i\n", i);
	//(*stack_a) = tmp_a;
	//print_stack(&stack_b, 0);
	print_stack(&stack_a, 1);*/
	
	//stack_b = tmp_b;
}