/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:13:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/09 16:23:01 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_parsing(int ac, char **av, t_vars *var)
{
	int	i;
	int	j;
	var->tmp_lst = NULL;
	var->size = 0;

	i = 0;
	if (ac == 2)
		var->tmp_lst = ft_split(av[1], ' ');
	else
	{
		j = 0;
		while (av[i])
			i++;
		var->tmp_lst = malloc(sizeof(char *) * i);
		i = 1;
		while(av[i])
			var->tmp_lst[j++] = av[i++];
	}
	j = 0;
	while(var->tmp_lst[j])
	{
		ft_check_number(var->tmp_lst[j++]);
		var->size++;
	}
	ft_int_tab(var);
}

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

void	ft_int_tab(t_vars *var)
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

void	ft_check_double(int	*tab, int i, t_vars *var)
{
	int	j;
	j = i + 1;
	if (i == var->size - 1)
		return;
	while (j < var->size)
	{
		if (tab[i] == tab[j])
			ft_putstr_exit("Error : Double !\n");
		j++;
	}
	ft_check_double(tab, i + 1, var);
}




