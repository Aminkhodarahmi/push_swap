/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:39:22 by akhodara          #+#    #+#             */
/*   Updated: 2023/04/14 12:42:43 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_list(t_stack *a, t_stack *b)
{
	t_innerstack	*tmp;
	t_innerstack	*del;

	del = a->p;
	while (del)
	{
		tmp = del;
		del = del->next;
		free(tmp);
	}
	free(a);
	del = b->p;
	while (del)
	{
		tmp = del;
		del = del->next;
		free(tmp);
	}
	free(b);
	return ;
}

int	dance_time(t_stack *a)
{
	t_innerstack	*tmp;

	tmp = a->p;
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	find_last(t_stack *x)
{
	t_innerstack	*find;
	int				tmp;

	find = x->p;
	tmp = find->nb;
	while (find->next)
	{
		tmp = find->next->nb;
		find = find->next;
	}
	return (tmp);
}

int	find_max(t_stack *x)
{
	int				max;
	t_innerstack	*inner_stack;

	max = INT_MIN;
	inner_stack = x->p;
	while (inner_stack)
	{
		if (inner_stack->nb > max)
			max = inner_stack->nb;
		inner_stack = inner_stack->next;
	}
	return (max);
}

int	find_min(t_stack *x)
{
	int				min_val;
	t_innerstack	*inner_stack;

	min_val = INT_MAX;
	inner_stack = x->p;
	while (inner_stack != NULL)
	{
		if (inner_stack->nb < min_val)
			min_val = inner_stack->nb;
		inner_stack = inner_stack->next;
	}
	return (min_val);
}
