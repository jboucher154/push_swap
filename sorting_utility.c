/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:51:58 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/21 11:57:19 by jebouche         ###   ########.fr       */
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

void	check_swaps_a(t_list **moves, t_list **lst_a, t_list **lst_b, int *ab_len)
{
	if (ab_len[0] > 1 && *((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data))
	{
		if (ab_len[1] > 1 && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data))
			add_move(moves, ss(lst_a, lst_b));
		else
			add_move(moves, sa(lst_a));
	}
}

void	check_swaps_b(t_list **moves, t_list **lst_a, t_list **lst_b, int *ab_len)
{
	if (ab_len[1] > 1 && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data))
	{
		if (ab_len[1] == 2 && ab_len[0] > 2)
		{
			add_move(moves, rrr(lst_a, lst_b));
		}
		else
		{
			add_move(moves, sb(lst_b));
		}
	}
}