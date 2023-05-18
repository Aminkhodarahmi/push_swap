/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:39:25 by akhodara          #+#    #+#             */
/*   Updated: 2023/04/14 12:51:41 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digit(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		if (str[j][i] == '-')
			i++;
		while (str[j][i])
			if (!ft_isdigit(str[j][i++]))
				return (0);
		j++;
	}
	return (j);
}

void	sort_t_stack(t_stack *a, t_stack *b, int size)
{
	if (dance_time(a) || size == 1)
		return ;
	if (size == 2)
	{
		if (a->p->nb > a->p->next->nb)
			swap_a(a, 1);
	}
	else if (size == 3)
		magic_sort(a);
	else if (size == 4 || size == 5)
		simple_sort(a, b, size);
	else if (size > 5 && size <= 100)
		true_sort(a, b, 8, size);
	else if (size > 100)
		true_sort(a, b, 16, size);
}
