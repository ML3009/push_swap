/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:37:09 by ml                #+#    #+#             */
/*   Updated: 2023/04/02 19:42:11 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* permet de connaitre la position du nombre dans la liste grace 
au tri de la stack_tmp*/
int get_position (t_lst *stack, int content)
{
    t_lst *tmp;
    int i;

    i = 0;
    tmp = stack;
    while (tmp->content != content)
    {
        i++;
        tmp = tmp->next;
    }
    return(i);
} 

/*me permet d avoir le nouveau pivot, souvent combiner avec position*/
int	ft_get_quick(t_lst *stack_tmp, int mid)
{
	t_lst *tmp;
	int i;

	tmp = stack_tmp;
	i = 0;
	while(i < mid)
	{
        tmp = tmp->next;
		i++;
	}
	return(tmp->content);
}

/*pourrait m etre utile pour savoir si mes petites listes sont triees*/

int	check_sorting(t_lst **stack1)
{
	t_lst	*tmp;

	tmp = (*stack1);
    while (tmp && tmp->next != NULL)
	{
        if (tmp->content > tmp->next->content)
        {
            return (0);
        }
        tmp = tmp->next;
	}
	return (1);

}
/* combine avec check sorting me permet de savoir si 
la totalite de ma liste est triee*/

int	check_sorting_a(t_lst **stack1, int count)
{
	int	len;

	len = ft_size_lst(*stack1);
	if (len != count)
    {
        return (0);
    }
    if (check_sorting(stack1) == 0)
		return (0);
	return (1);
}

void    ft_search_next_max(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var)
{
    /*objectif = chercher le max suivant et donc etre sur que sa position est la bonne. 
    gerer la premiere fois que je push le max puisque sa position sera forcement ok
    pour le reste comparer au content d a cote afin d etre sur
    que le content 
    avoir en memoir le var->max, et la position de ce var->max
    verifier que le var->max et le presuppose var->next->max 
    sont aux bonnes posiitons. sous entendu 
    if var->max_pos_next = var->max_pos + 1 
    alors cest GOOD le var_max_pos_next devient le var_max_pos*/
    (void)stack_b;
    (void)stack_a;
    int max;
    int next_max;
    max = get_position((*stack_tmp), var->max);
    next_max = ft_get_next_max((*stack_tmp), max);
    var->max = next_max;  
    if(var->max < var->mid)
        var->mid = var->max;
      if (var->max == 1)
      {
         print_stack(stack_a, 1);
        print_stack(stack_b, 0); 
            printf(" var max %i\n", var->max);
       printf("STOP : %i\n", var->stop);
          printf("var->mid FIN %i\n", var->mid);
        printf("var->min FIN %i\n", var->min);
       //exit(EXIT_SUCCESS);
    }
}


