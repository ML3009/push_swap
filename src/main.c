/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:36:21 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/09 17:06:21 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_vars	var;
	t_list *stack;
	t_list *tmp;
	int	i;
	int	temp;

	stack = NULL;
	i = 0;
	if (ac < 2)
		ft_putstr_exit("Error : Wrong number of argument\n");
	ft_parsing(ac, av, &var);
	while (i  < var.size)
	{
		temp = ft_atoi(var.tmp_lst[i]);
		tmp = ft_lstnew(temp);
		ft_lstadd_back(&stack, tmp);
		printf("stack : [%i]\n",stack->content);
		i++;
	}
	ft_printf("full\n");
	t_list *tampon;

	tampon = stack;
	while(tampon)
	{
    	printf("tampon : [%i]\n",tampon->content);
    	tampon = tampon->next;
	}

	/*while(stack)
	{
		printf("stack : [%i]\n",*((int *)stack->content));
		stack = stack->next;
	}*/
	return(0);
}
