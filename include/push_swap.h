/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:34:11 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/09 20:26:40 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "limits.h"

//strucutre taille liste + tmp_list;

typedef	struct s_vars
{
	char **tmp_lst;
	int	size;

}	t_vars;

typedef struct s_lst
{
	int			content;
	struct s_lst	*next;
}t_lst;


/*PARSING*/

void	ft_check_number(char *av);
void	ft_int_tab(t_vars *var);
void	ft_parsing(int ac, char **av, t_vars *var);
void	ft_check_double(int	*tab, int i, t_vars *var);

/*STACK*/

t_lst	*ft_new_element(int content);
t_lst	*ft_last_lst(t_lst *lst);
void	ft_add_back_lst(t_lst **lst, t_lst *new);
void	ft_add_front_lst(t_lst	**lst, t_lst *new);
void	ft_init_stack(t_vars *var, t_lst **stack_a, t_lst **stack_b);


/*MOVE*/
void	ft_stack_move(t_lst *stack_a, t_lst *stack_b);
void	ft_swap_a(t_lst *stack_a, int i);
void	ft_swap_b(t_lst *stack_b, int i);
void	ft_swap_a_b(t_lst *stack_a, t_lst *stack_b);
void	ft_push_a(t_lst	*stack_a, t_lst *stack_b, int i);

/*UTILS*/

void	ft_putstr_exit(char *str);

void print_stack(t_lst **stack);

#endif
