/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:51:58 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/27 11:02:39 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_move(t_list **moves, char *move)
{
		t_list	*new;

	new = ft_lstnew(move);
	if (!new)
		return ; //exit?
	ft_lstadd_back(moves, new);
}

void	check_swaps_a(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	if (!lst_a || !(*lst_a))
		return ;
	if ((*lst_a)->next && *((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data))
	{
		if ((*lst_b) && (*lst_b)->next && *((int *)(*lst_b)->data) < *(int *)(*lst_b)->next->data)
			add_move(moves, ss(lst_a, lst_b));
		else
			add_move(moves, sa(lst_a));
	}
}

void	check_swaps_b(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	if (lst_b == NULL || *lst_b == NULL)
		return ;
	if ((*lst_b)->next && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data))
	{
		if ((*lst_b)->next->next != NULL && (*lst_a)->next->next != NULL)
			add_move(moves, rrr(lst_a, lst_b));
		else
			add_move(moves, sb(lst_b));
	}
}
