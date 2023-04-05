/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:37:09 by ml                #+#    #+#             */
/*   Updated: 2023/04/05 09:28:52 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* permet de connaitre la position du nombre dans la liste grace
au tri de la stack_tmp*/
int ft_get_position (t_lst *stack, int content)
{
    t_lst *tmp;
    int i;

    i = 0;
    tmp = stack;
    while (tmp->content != content)
    {
        i++;
        tmp = tmp->next;
    }
    return(i);
}

/*me permet d avoir le nouveau pivot, souvent combiner avec position*/
int	ft_get_quick(t_lst *stack_tmp, int mid)
{
	t_lst *tmp;
	int i;

	tmp = stack_tmp;
	i = 0;
	while(i < mid)
	{
        tmp = tmp->next;
		i++;
	}
	return(tmp->content);
}

int	ft_check_sorting(t_lst **stack)
{
	t_lst	*tmp;

	tmp = (*stack);
    while (tmp && tmp->next != NULL)
	{
        if (tmp->content > tmp->next->content)
        {
            return (0);
        }
        tmp = tmp->next;
	}
	return (1);

}

int	ft_check_sorting_stack(t_lst **stack, int count)
{
	int	len;

	len = ft_size_lst(*stack);
	if (len != count)
    {
        return (0);
    }
    if (ft_check_sorting(stack) == 0)
		return (0);
	return (1);
}


