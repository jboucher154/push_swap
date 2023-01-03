/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:51:58 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/28 16:30:10 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_move(t_list **moves, char *move)
{
		t_list	*new;

	new = ft_lstnew(move);
	if (!new)
		return (0); //exit?
	ft_lstadd_back(moves, new);
	return (1);
}

void	check_swaps_a(t_list **moves, t_list **lst_a)
{
	if (!lst_a || !(*lst_a))
		return ;
	if ((*lst_a)->next && *((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data))
			add_move(moves, sa(lst_a));
}

void	check_swaps_b(t_list **moves, t_list **lst_b)
{
	if (lst_b == NULL || *lst_b == NULL)
		return ;
	if ((*lst_b)->next && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data))
			add_move(moves, sb(lst_b));
}

void	rev_rotate_a(t_list **moves, t_list **lst_a, int rotation)
{
	while (rotation)
		rotation -= add_move(moves, rra(lst_a));
}

void	rotate_a(t_list **moves, t_list **lst_a, int rotation)
{
	while (rotation)
		rotation -= add_move(moves, ra(lst_a));

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
	int to_add;
	
	rotated = 0;
	pushed = 0;
	to_add = *((int *)(*lst_b)->data);
	if (to_add < *((int *)(*lst_a)->data) || (to_add > *((int *)(*lst_a)->data) && to_add < *((int *)(*lst_a)->next->data)))//removed *((int *)(*lst_b)->data) < *((int *)(*lst_a)->next->data)
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


// void	check_swaps_a(t_list **moves, t_list **lst_a, t_list **lst_b)
// {
// 	if (!lst_a || !(*lst_a))
// 		return ;
// 	if ((*lst_a)->next && *((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data))
// 	{
// 		if ((*lst_b) && (*lst_b)->next && *((int *)(*lst_b)->data) < *(int *)(*lst_b)->next->data)
// 			add_move(moves, ss(lst_a, lst_b));
// 		else
// 			add_move(moves, sa(lst_a));
// 	}
// }

// void	check_swaps_b(t_list **moves, t_list **lst_a, t_list **lst_b)
// {
// 	if (lst_b == NULL || *lst_b == NULL)
// 		return ;
// 	if ((*lst_b)->next && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data))
// 	{
// 		if ((*lst_b)->next->next != NULL && (*lst_a)->next->next != NULL)
// 			add_move(moves, rrr(lst_a, lst_b));
// 		else
// 			add_move(moves, sb(lst_b));
// 	}
// }