/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:51:58 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/04 11:24:14 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_swaps_a(t_list **moves, t_list **lst_a)
{
	if (!lst_a || !(*lst_a))
		return ;
	if ((*lst_a)->next && *((int *)(*lst_a)->data) > \
		*((int *)(*lst_a)->next->data))
		add_move(moves, sa(lst_a));
}

int	rev_rotate_a(t_list **moves, t_list **lst_a, int rotation)
{
	int	rotated;

	rotated = rotation;
	while (rotation)
		rotation -= add_move(moves, rra(lst_a));
	return (rotated);
}

int	rotate_a(t_list **moves, t_list **lst_a, int rotation)
{
	int	rotated;

	rotated = rotation;
	while (rotation)
		rotation -= add_move(moves, ra(lst_a));
	return (rotated);
}

int	rotate_a_toadd(t_list **moves, t_list **lst_a, int to_add)
{
	int	rotated;

	rotated = 0;
	while (*(int *)(*lst_a)->next->data < to_add)
		rotated += add_move(moves, ra(lst_a));
	return (rotated);
}

int	push_to_a(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	int	pushed;
	int	rotated;
	int	to_add;

	rotated = 0;
	pushed = 0;
	to_add = *((int *)(*lst_b)->data);
	if (to_add < *((int *)(*lst_a)->data) || (to_add > *((int *)(*lst_a)->data) \
		&& to_add < *((int *)(*lst_a)->next->data)))
	{
		pushed = add_move(moves, pa(lst_a, lst_b));
		check_swaps_a(moves, lst_a);
	}
	else
	{
		rotated = rotate_a_toadd(moves, lst_a, to_add);
		pushed = push_to_a(moves, lst_a, lst_b);
		rev_rotate_a(moves, lst_a, rotated);
	}
	return (pushed);
}
