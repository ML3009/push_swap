/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:38:28 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/20 13:45:29 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_putstr_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
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
            ft_printf("index : [ %i ]",tmp->index);
            ft_printf(" stack B : [ %i ]\n",tmp->content);
            tmp = tmp->next;
        }
        ft_printf("index : [ %i ]",tmp->index);
	    ft_printf(" stack B : [ %i ]",tmp->content);
	    ft_printf("\n");
        ft_printf("\n");
    }
    else
    {
        while (tmp->next)
        {
            ft_printf("index : [ %i ]",tmp->index);
            ft_printf(" stack : [ %i ]\n",tmp->content);
            tmp = tmp->next;
        }
        ft_printf("index : [ %i ]",tmp->index);
	    ft_printf(" stack : [ %i ]",tmp->content);
	    ft_printf("\n");
        ft_printf("\n");
    }
}

void	ft_stack_init(t_vars *var, t_lst **stack_a, t_lst **stack_tmp)
{
	int	i;
	int	temp;
	t_lst *tmp;

	i = 0;
	while (i < var->size)
	{
		temp = ft_atoi(var->tmp_lst[i]);
		tmp = ft_new_element(temp);
		ft_add_back_lst(stack_a, tmp);
		i++;
	}
	i = 0;
	while (i < var->size)
	{
		temp = ft_atoi(var->tmp_lst[i]);
		tmp = ft_new_element(temp);
		ft_add_back_lst(stack_tmp, tmp);
		i++;
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
	//t_lst *tmp;
	//tmp = stack_tmp;

	while(stack_tmp->next)
	{
		if(stack_tmp->index == mid)
			return(stack_tmp->content);
        stack_tmp = stack_tmp->next;
	}
    //stack_tmp = tmp;
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

int	ft_get_new_pivot(t_lst *stack)
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
