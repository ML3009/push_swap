/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:36:21 by mvautrot          #+#    #+#             */
/*   Updated: 2023/04/14 10:23:22 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_vars	var;
	t_lst	*stack_a;
	t_lst	*stack_b;
	t_lst	*stack_tmp;

	stack_a = NULL;
	stack_b = NULL;
	stack_tmp = NULL;
	var.tmp_lst = NULL;
	var.size = 0;
	var.ac = ac;
	ft_back_up_lst(ac, av, &var);
	ft_parsing(&var);
	ft_stack_init(&var, &stack_a, &stack_tmp);
	var.count = 0;
	ft_sort_list(stack_tmp);
	ft_get_index(stack_tmp);
	ft_check_stack(&var, &stack_a, &stack_b, &stack_tmp);
	ft_free_lst(stack_tmp);
	ft_free_lst(stack_a);
	return (0);
}
