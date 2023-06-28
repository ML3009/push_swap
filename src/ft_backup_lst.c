/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:38:28 by mvautrot          #+#    #+#             */
/*   Updated: 2023/04/14 10:45:47 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_back_up_lst(int ac, char **av, t_vars *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac == 2)
	{
		var->tmp_lst = ft_split(av[1], ' ');
		while (var->tmp_lst[i] != NULL)
			i++;
		if (i <= 1)
			ft_free_tmp(var, "Error\n");
	}
	else if (ac > 2)
	{
		ft_back_up_lst_2(av, var);
	}
	else
		ft_putstr_exit("Error\n");
}

void	ft_back_up_lst_2(char **av, t_vars *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
		i++;
	var->tmp_lst = malloc(sizeof(char *) * i);
	i = 1;
	while (av[i])
		var->tmp_lst[j++] = av[i++];
	var->tmp_lst[j] = NULL;
}
