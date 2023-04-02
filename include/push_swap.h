/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:34:11 by mvautrot          #+#    #+#             */
/*   Updated: 2023/04/02 12:16:09 by ml               ###   ########.fr       */
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
	int	min;
	int	mid;
	int	mid_0;
	int	mid_1;
	int mid_2;
	int	max;
	int	check;
	int	end;
	int	stop;
	int	tmp;

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

/*STACK CREATION*/

t_lst	*ft_new_element(int content);
t_lst	*ft_last_lst(t_lst *lst);
void	ft_add_back_lst(t_lst **lst, t_lst *new);
void	ft_add_front_lst(t_lst	**lst, t_lst *new);
int	ft_size_lst(t_lst *lst);

/*STACK GESTION*/
void	ft_stack_init(t_vars *var, t_lst **stack_a, t_lst **stack_tmp);
void	ft_check_stack(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp);

/*STACK SORT*/
void	ft_sort_list(t_lst *stack_tmp);
int	ft_sort_same(t_lst *stack_a, t_lst *stack_tmp, t_vars *var);
void	ft_sort_3(t_lst	*stack_a, t_lst *stack_b, int pivot);
void	ft_sort_10(t_vars *var, t_lst *stack_a, t_lst *stack_b, int pivot);

void	ft_quicksort(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp);
void    ft_quick_a(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var);
void    ft_quick_b(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var);
void    ft_search_next_max(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var);

void    ft_push_min(t_vars *var, t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp);
void ft_replace_max(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var);

int	ft_get_next_max(t_lst *stack, int size);

void    ft_replace_min(t_lst **stack_a, t_lst **stack_b, t_lst **stack_tmp, t_vars *var);

int	ft_get_end(t_lst *stack);

int	ft_get_quick(t_lst *stack_tmp, int mid);


int get_position (t_lst *stack, int content);

/*STACK MOVES*/

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


/*STACK UTILS */
int	ft_get_min(t_lst *stack);
int	ft_get_max(t_lst *stack);
int	ft_get_new_pivot(t_lst *stack);
void	ft_get_index(t_lst *stack_tmp);
int	ft_get_pivot(t_lst *stack_tmp, int mid);


/*UTILS*/

void	ft_putstr_exit(char *str);
void print_stack(t_lst **stack, int i);

int	check_sorting(t_lst **stack1);
int	check_sorting_a(t_lst **stack1, int count);

int	ft_get_min_index(t_lst *stack);
int	ft_get_max_index(t_lst *stack);

#endif
