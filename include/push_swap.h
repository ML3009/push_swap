/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:34:11 by mvautrot          #+#    #+#             */
/*   Updated: 2023/03/20 13:14:04 by mvautrot         ###   ########.fr       */
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
	int	index;
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
void	ft_stack_init(t_vars *var, t_lst **stack_a, t_lst **stack_tmp);
void	ft_sort_list(t_lst *stack_tmp);
int	ft_size_lst(t_lst *lst);


/*MOVE*/
void	ft_stack_move(t_lst *stack_a, t_lst *stack_b);
void	ft_sa(t_lst *stack_a, int i);
void	ft_sb(t_lst *stack_b, int i);
void	ft_ss(t_lst *stack_a, t_lst *stack_b);
void	ft_pb(t_lst	**stack_a, t_lst **stack_b);
void	ft_pa(t_lst **stack_a, t_lst ** stack_b);
void	ft_ra(t_lst *stack_a, int i);
void	ft_rb(t_lst *stack_b, int i);
void	ft_rr(t_lst *stack_a, t_lst *stack_b);
void	ft_rra(t_lst *stack_a, int i);
void	ft_rrb(t_lst *stack_b, int i);
void	ft_rrr(t_lst *stack_a, t_lst *stack_b);

void	ft_sort_3(t_lst	*stack_a, t_lst *stack_b, int pivot);

void	ft_check_list(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp);

int	ft_get_min(t_lst *stack);
int	ft_get_max(t_lst *stack);
int	ft_get_new_pivot(t_lst *stack);

void	ft_sort_pivot(t_vars *var, t_lst *stack_a, t_lst *stack_b, int pivot);
/*UTILS*/

void	ft_putstr_exit(char *str);
void	ft_get_index(t_lst *stack_tmp);
int	ft_get_pivot(t_lst *stack_tmp, int mid);
int	ft_sort_same(t_lst *stack_a, t_lst *stack_tmp, t_vars *var);
void print_stack(t_lst **stack, int i);

#endif
