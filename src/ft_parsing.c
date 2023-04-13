/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:13:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/04/13 15:25:12 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_parsing(int ac, char **av, t_vars *var)
{
	int	i;
	int	j;

	var->tmp_lst = NULL;
	var->size = 0;
	var->ac = ac;
	i = 0;
	j = 0;
	if (ac == 2)
	{
		var->tmp_lst = ft_split(av[1], ' ');
		while (var->tmp_lst[i] != NULL)
			i++;
		if (i == 1)
			ft_free_tmp(var, "Error\n");
	}
	else if (ac > 2)
	{
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
	else
		ft_putstr_exit("Error\n");
	j = 0;
	while (var->tmp_lst[j])
	{
		if (!ft_check_number(var->tmp_lst[j++]))
			ft_free_tmp(var, "Error\n");
		var->size++;
	}
	ft_int_tab(var);
}

int	ft_check_number(char *av)
{
	long long	nb;
	int			i;

	nb = ft_atoi(av);
	i = 0;
	while (av[i])
	{
		if ((!(ft_isdigit(av[i]))) && (!((av[i] == '-'
						|| av[i] == '+') && ft_isdigit(av[i + 1]))))
			return (0);
		i++;
	}
	if ((nb < INT_MIN || nb > INT_MAX))
		return (0);
	return (1);
}

void	ft_int_tab(t_vars *var)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * var->size);
	if (!tab)
		return ;
	while (var->tmp_lst[i])
	{
		tab[i] = ft_atoi(var->tmp_lst[i]);
		i++;
	}
	i = 0;
	ft_check_double(tab, i, var);
	free(tab);
}

void	ft_check_double(int	*tab, int i, t_vars *var)
{
	int	j;

	j = i + 1;
	if (i == var->size - 1)
		return ;
	while (j < var->size)
	{
		if (tab[i] == tab[j])
		{
			free(tab);
			ft_free_tmp(var, "Error\n");
		}
		j++;
	}
	ft_check_double(tab, i + 1, var);
}
