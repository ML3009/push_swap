/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:38:28 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/09 19:58:18 by mvautrot         ###   ########.fr       */
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
    while (tmp->next)
    {
        ft_printf("[ %i ]",tmp->content);
        tmp = tmp->next;
    }
	ft_printf("[ %i ]",tmp->content);
	ft_printf("\n");
}
