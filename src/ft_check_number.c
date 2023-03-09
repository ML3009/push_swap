/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:13:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/09 14:26:56 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_number(char *av)
{
	long long	nb;
	int	i;


	nb = ft_atoi(av);
	i = 0;
	while (av[i])
	{
		if((!(ft_isdigit(av[i]))) && (!((av[i] == '-' || av[i] == '+') && ft_isdigit(av[i + 1]))))
			ft_putstr_exit("Error : Isn't digit\n");
		i++;
	}
	if ((nb < INT_MIN || nb > INT_MAX))
			ft_putstr_exit("Error : Isn't valid digit\n");
}

//recursive

void	ft_init_tab(t_vars *var)
{
	int	i;
	int *tab;

	i = 0;
	tab = malloc(sizeof(int) * var->size);
	if (!tab)
		return;
	while (var->tmp_lst[i])
	{
		tab[i] = ft_atoi(var->tmp_lst[i]);
		i++;
	}
	i = 0;
	ft_check_double(tab, i, var);
}

int	ft_check_double(int	*tab, int i, t_vars *var)
{
	int	j;
	j = i + 1;
	if (i == var->size - 1)
		return(1);
	while (j < var->size)
	{
		if (tab[i] == tab[j])
			ft_putstr_exit("Error : Double !\n");
		j++;
	}
	ft_check_double(tab, i + 1, var);
	return (1);
}


void	ft_init(t_vars *var)
{
	var->tmp_lst = NULL;
	var->size = 0;
}



