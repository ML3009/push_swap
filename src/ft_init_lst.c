/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:10:27 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/10 10:52:57 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*ft_new_element(int content)
{
	t_lst	*element;

	element = malloc(sizeof(t_lst));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}

t_lst	*ft_last_lst(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_add_back_lst(t_lst **lst, t_lst *new)
{
	t_lst	*str;

	if (!*lst)
		*lst = new;
	else
	{
		str = ft_last_lst(*lst);
		str->next = new;
	}
}

void	ft_add_front_lst(t_lst	**lst, t_lst *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

/*void	ft_free_element(t_lst **lst, t_lst *element)
{
	t_lst	*tmp;
	int	temp;

	tmp = lst;

	temp = lst->next->content;


}*/

void	ft_init_stack(t_vars *var, t_lst **stack_a, t_lst **stack_b)
{
	int	i;
	int	temp;
	t_lst *tmp;
	(void)stack_b;

	i = 0;
	while (i < var->size)
	{
		temp = ft_atoi(var->tmp_lst[i]);
		tmp = ft_new_element(temp);
		ft_add_back_lst(stack_a, tmp);
		i++;
	}
	//i = 0;
	//while (i < var->size)
	//{
	//	temp = ft_atoi(var->tmp_lst[i]);
	//	tmp = ft_new_element(temp);
	//	ft_add_back_lst(stack_b, tmp);
	//	i++;
	//}
}
