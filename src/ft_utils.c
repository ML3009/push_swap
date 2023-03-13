/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:38:28 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/13 13:10:21 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_putstr_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void print_stack(t_lst **stack)
{
    t_lst *tmp;

    tmp = *stack;
    if (*stack == NULL) {
        ft_printf("[ Empty ]\n");
        return;}
    while (tmp->next)
    {
        ft_printf("index : [ %i ]",tmp->index);
        ft_printf(" stack : [ %i ]\n",tmp->content);
        tmp = tmp->next;
    }
    ft_printf("index : [ %i ]",tmp->index);
	ft_printf(" stack : [ %i ]",tmp->content);
	ft_printf("\n");
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