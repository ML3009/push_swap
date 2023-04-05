/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:38:28 by mvautrot          #+#    #+#             */
/*   Updated: 2023/04/05 11:18:29 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_putstr_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_free_lst(t_lst *stack)
{
	t_lst	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = (stack)->next;
		free(stack);
		(stack) = tmp;
	}
}

void	ft_get_index(t_lst *stack_tmp)
{
	t_lst	*tmp;
	int	i;

	i = 0;
	tmp = stack_tmp;
	while(stack_tmp->next)
	{
		stack_tmp->index = i;
		stack_tmp = stack_tmp->next;
		i++;
	}
	stack_tmp->index = i;
	stack_tmp = tmp;
}

int	ft_get_pivot(t_lst *stack_tmp, int mid)
{
	ft_get_index(stack_tmp);
	while(stack_tmp->next)
	{
		if(stack_tmp->index == mid)
			return(stack_tmp->content);
        stack_tmp = stack_tmp->next;
	}
	return (0);
}



int	ft_get_min(t_lst *stack)
{
	t_lst	*tmp;
	int	min;

	tmp = stack;
	min = stack->content;
	while(stack->next)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	if (stack->content < min)
		min = stack->content;
	stack = tmp;
	return(min);
}


int	ft_get_max(t_lst *stack)
{
	t_lst	*tmp;
	int	max;

	tmp = stack;
	max = stack->content;
	while(stack->next)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	if (stack->content > max)
		max = stack->content;
	stack = tmp;
	return(max);
}

int	ft_get_pivot_10(t_lst *stack)
{
	int	max;
	int	min;

	min = ft_get_min(stack);
	max = ft_get_max(stack);
	while (stack->next)
	{
		if (stack->content > min && stack->content < max)
			return (stack->content);
		stack = stack->next;
	}
	if (stack->content > min && stack->content < max)
		return (stack->content);
	return (0);
}


void print_all_pile(t_lst **a, t_lst **b)
{
    t_lst *tmp_a;
    t_lst *tmp_b;

    tmp_a = (*a);
    tmp_b = (*b);

    ft_printf("\t[ A ]\t|   [ B ]\n");
    ft_printf("       --------------------\n");
    while (tmp_a || tmp_b)
    {
        if (tmp_a && tmp_b)
        {

            ft_printf("\t[ %i ]\t|",tmp_a->content);
            ft_printf("   [ %i ]\n",tmp_b->content);
            tmp_a = tmp_a->next;
            tmp_b = tmp_b->next;
        }
        else if (tmp_a && !tmp_b)
        {
            ft_printf("\t[ %i ]\t|\t\n",tmp_a->content);
            tmp_a = tmp_a->next;
        }
        else if (!tmp_a && tmp_b)
        {
            ft_printf("\t\t|   [ %i ]\n",tmp_b->content);
            tmp_b = tmp_b->next;
        }
        else
            ft_printf("[ Empty ]\t|\t[ Empty ]\n");
    }
    ft_printf("       --------------------\n\n");
}

void print_stack(t_lst **stack, int i)
{
    t_lst *tmp;

    tmp = *stack;
    if (*stack == NULL) {
        ft_printf("[ Empty ]\n");
        return;}
    if (i == 0)
    {
        while (tmp->next)
        {
           // ft_printf("index : [ %i ]",tmp->index);
            ft_printf(" stack B : [ %i ]\n",tmp->content);
            tmp = tmp->next;
        }
        //ft_printf("index : [ %i ]",tmp->index);
	    ft_printf(" stack B : [ %i ]",tmp->content);
	    ft_printf("\n");
        ft_printf("\n");
    }
    else
    {
        while (tmp->next)
        {
           // ft_printf("index : [ %i ]",tmp->index);
            ft_printf(" stack : [ %i ]\n",tmp->content);
            tmp = tmp->next;
        }
       // ft_printf("index : [ %i ]",tmp->index);
	    ft_printf(" stack : [ %i ]",tmp->content);
	    ft_printf("\n");
        ft_printf("\n");
    }
}
