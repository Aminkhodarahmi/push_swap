/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondmoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:39:16 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/17 17:29:20 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *a, int bool)
{
	int				tmp;
	t_innerstack	*rot;
	t_innerstack	*rot2;
	t_innerstack	*new;

	if (a->p == NULL || a->p->next == NULL)
		return ;
	rot = a->p;
	tmp = rot->nb;
	rot2 = rot->next;
	free(rot);
	a->p = rot2;
	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->nb = tmp;
	new->next = NULL;
	while (rot2->next != NULL)
		rot2 = rot2->next;
	rot2->next = new;
	if (bool)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *b, int bool)
{
	int				tmp;
	t_innerstack	*rot;
	t_innerstack	*rot2;
	t_innerstack	*new;

	if (b->p == NULL)
		return ;
	rot = b->p;
	if (rot->next == NULL)
		return ;
	tmp = rot->nb;
	rot2 = rot->next;
	free(rot);
	b->p = rot2;
	new = malloc(sizeof(*new));
	new->nb = tmp;
	new->next = NULL;
	while (rot2->next != NULL)
		rot2 = rot2->next;
	rot2->next = new;
	if (bool)
		write(1, "rb\n", 3);
}

void	rotate(t_stack *a, t_stack *b)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_stack *a, int bool)
{
	int				tmp;
	t_innerstack	*rot;
	t_innerstack	*temp;

	if (a->p == NULL)
		return ;
	rot = a->p;
	if (rot->next == NULL)
		return ;
	while (rot->next != NULL)
		rot = rot->next;
	tmp = rot->nb;
	insert(a, tmp);
	rot = a->p;
	while (rot->next->next != NULL)
		rot = rot->next;
	temp = rot->next;
	rot->next = NULL;
	free(temp);
	if (bool)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *b, int bool)
{
	int				tmp;
	t_innerstack	*rot;
	t_innerstack	*temp;

	if (b->p == NULL)
		return ;
	rot = b->p;
	if (rot->next == NULL)
		return ;
	while (rot->next != NULL)
		rot = rot->next;
	tmp = rot->nb;
	insert(b, tmp);
	rot = b->p;
	while (rot->next->next != NULL)
		rot = rot->next;
	temp = rot->next;
	rot->next = NULL;
	free(temp);
	if (bool)
		write(1, "rrb\n", 4);
}
