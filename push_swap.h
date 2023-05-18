/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:39:13 by akhodara          #+#    #+#             */
/*   Updated: 2023/04/17 13:08:00 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <limits.h>

//struct def
typedef struct s_innerstack
{
	int					nb;
	struct s_innerstack	*next;
}t_innerstack;

typedef struct s_stack
{
	struct s_innerstack	*p;
}t_stack;

//push_swap.c
int		*check_args(int argc, char **argv, int	*size);
void	insert(t_stack *x, int nb);
void	reverse_rotate(t_stack *a, t_stack *b);

//sorting.c
void	magic_sort(t_stack *a);
void	simple_sort(t_stack *a, t_stack *b, int size);
void	true_sort(t_stack *a, t_stack *b, int chunksize, int size);

//big_sort.c
int		find_chunk_ra(t_stack *a, int chunksize, int value);
int		find_chunk_rra(t_stack *a, int chunksize, int value, int size);
int		find_way(t_stack *a);
void	sort_it_out(t_stack *a, t_stack*b);
int		digit(char **str);
int		*convert_intfromchar(char **argv, int *size);
void	sort_t_stack(t_stack *a, t_stack *b, int size);
//first_moves.c
void	swap_a(t_stack *a, int bool);
void	swap_b(t_stack *b, int bool);
void	swap(t_stack *a, t_stack *b);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

//second_moves.c
void	rotate_a(t_stack *a, int bool);
void	rotate_b(t_stack *b, int bool);
void	rotate(t_stack *a, t_stack *b);
void	reverse_rotate_a(t_stack *a, int bool);
void	reverse_rotate_b(t_stack *b, int bool);

//tools.c
void	clean_list(t_stack *a, t_stack *b);
int		dance_time(t_stack *a);
int		find_min(t_stack *x);
int		find_max(t_stack *x);
int		find_last(t_stack *x);

//index.c
void	index_array(int *array, int size);

#endif