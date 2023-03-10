/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:59:05 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/10 11:59:25 by mvautrot         ###   ########.fr       */
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
