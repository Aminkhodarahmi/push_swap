/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:39:10 by akhodara          #+#    #+#             */
/*   Updated: 2023/04/27 17:16:00 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra and rrb at the same time.
void	reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate_a(a, 0);
	reverse_rotate_b(b, 0);
	ft_printf("rrr\n");
}

t_stack	*initialize_t_stack(void)
{
	t_innerstack	*new;
	t_innerstack	*del;
	t_stack			*controlt_stack;

	new = malloc(sizeof(*new));
	controlt_stack = malloc(sizeof(*controlt_stack));
	if (new == NULL || controlt_stack == NULL)
		return (NULL);
	new->next = NULL;
	controlt_stack->p = new;
	del = controlt_stack->p;
	controlt_stack->p = controlt_stack->p->next;
	free(del);
	return (controlt_stack);
}

void	insert(t_stack *x, int nb)
{
	t_innerstack	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (x == NULL || tmp == NULL)
		return ;
	tmp->nb = nb;
	if (!x->p)
		tmp->next = NULL;
	else
		tmp->next = x->p;
	x->p = tmp;
}

void	ft_func(t_stack	*a, t_stack	*b, int argc, char **argv)
{
	int		*tmp;
	int		size;
	int		i;

	i = 0;
	size = 0;
	tmp = check_args(argc, argv, &size);
	if (!tmp)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	index_array(tmp, size);
	a = initialize_t_stack();
	while (size - i++)
		insert(a, tmp[size - i]);
	free(tmp);
	b = initialize_t_stack();
	sort_t_stack(a, b, size);
	clean_list(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
		ft_func(a, b, argc, argv);
	return (0);
}
