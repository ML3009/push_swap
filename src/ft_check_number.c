/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:13:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/08 18:50:16 by mvautrot         ###   ########.fr       */
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
			ft_putstr_fd("Error : Isn't digit\n", 2);
		i++;
	}
	if ((nb < INT_MIN || nb > INT_MAX))
			ft_putstr_fd("Error : Isn't valid digit\n", 2);
}

//recursive

void	ft_check_double(t_vars *var)
{
	int	i;
	int	j;
	int	nb;
	int	*tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int) * var->size);
	while (i < var->size)
	{
		nb = ft_atoi(var->tmp_lst[i]);
		tab[j] = ft_atoi(var->tmp_lst[i]);
		j++;
		i++;
		ft_printf("%i | ",j);
	}
	ft_printf("ok\n");
	//tab[j] = ft_atoi(var->tmp_lst[i]);
	j = 0;
	while (tab[j])
		ft_printf("tab : %i\n", tab[j++]);



/*
	while (var->tmp_lst[i])
		tab[j++] = ft_atoi(tmp_lst[i]);

	j = 0;*/
	while (tab[j])
		ft_printf("tab : %i\n", tab[j++]);
}

void	ft_init(t_vars *var)
{
	var->tmp_lst = NULL;
	var->size = 0;
}



