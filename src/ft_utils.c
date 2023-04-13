/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:38:28 by mvautrot          #+#    #+#             */
/*   Updated: 2023/04/13 15:28:47 by mvautrot         ###   ########.fr       */
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

void	ft_free_tmp(t_vars *var, char *str)
{
	ft_putstr_fd(str, 2);
	if (var->ac == 2)
		ft_free_tab(var->tmp_lst);
	else if (var->ac > 2)
		free(var->tmp_lst);
	exit(EXIT_FAILURE);
}
