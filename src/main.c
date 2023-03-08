/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:36:21 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/08 18:11:07 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

int	main(int ac, char **av)
{
	int	i;
	int	j;
	t_vars	var;

	ft_init(&var);

	i = 0;
	if (ac < 2)
		ft_putstr_fd("Error : Wrong number of argument\n", 2);
	if (ac == 2)
		var.tmp_lst = ft_split(av[1], ' ');
	else
	{
		j = 0;
		while (av[i])
			i++;
		var.tmp_lst = malloc(sizeof(char *) * i);
		i = 1;
		while(av[i])
			var.tmp_lst[j++] = av[i++];
	}
	j = 0;
	while(var.tmp_lst[j])
	{
		ft_check_number(var.tmp_lst[j++]);
		var.size++;
	}
	printf("var.size : %i\n", var.size);
	ft_check_double(&var);
	return(0);
}


//i = 1;
//j=0;
//while(av[i])
//vattmp[j] = av[i]
