/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:36:21 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/10 16:21:10 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_vars	var;
	t_lst	*stack_a;
	t_lst	*stack_b;
	t_lst	*stack_tmp;

	stack_a = NULL;
	stack_b = NULL;
	stack_tmp = NULL;
	if (ac < 2)
		ft_putstr_exit("Error : Wrong number of argument\n");
	ft_parsing(ac, av, &var);
	ft_stack_init(&var, &stack_a, &stack_tmp);
	ft_sort_list(stack_tmp);
	print_stack(&stack_tmp);
	//ft_stack_move(stack_a, stack_tmp);



	return(0);
}

