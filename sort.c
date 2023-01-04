/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:55:27 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/04 11:33:11 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	if (*(int *)(*lst_a)->data < *(int *)(*lst_a)->next->data)
	{
		if (*(int *)(*lst_a)->data > *(int *)(*lst_a)->next->next->data)
			add_move(moves, rra(lst_a));
	}
	else if (*(int *)(*lst_a)->data > *(int *)(*lst_a)->next->data)
	{
		if (*(int *)(*lst_a)->data > *(int *)(*lst_a)->next->next->data)
			add_move(moves, ra(lst_a));
	}
	if (!check_if_sorted(*lst_a))
	{
		if (*lst_b && (*lst_b)->next && *(int *)(*lst_b)->data < \
			*(int *)(*lst_b)->next->data)
			add_move(moves, ss(lst_a, lst_b));
		else
			add_move(moves, sa(lst_a));
		sort_three(moves, lst_a, lst_b);
	}
}

static void	sort_two(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a)->next && *((int *)(*lst_a)->data) > \
		*((int *)(*lst_a)->next->data))
	{
		if (*lst_b && (*lst_b)->next && *(int *)(*lst_b)->data < \
			*(int *)(*lst_b)->next->data)
			add_move(moves, ss(lst_a, lst_b));
		else
			add_move(moves, sa(lst_a));
	}
}

t_list	*sort_list(t_list **lst_a)
{
	t_list	*lst_b;
	t_list	*moves;
	t_list	*part_sizes;
	int		len;

	lst_b = NULL;
	moves = NULL;
	part_sizes = NULL;
	if (!lst_a && !(*lst_a))
		return (NULL);
	len = ft_lstsize(*lst_a);
	if ((*lst_a)->next == NULL || check_if_sorted(*lst_a))
		return (moves);
	else
	{
		if (len > 3)
			divide(&moves, lst_a, &lst_b, &part_sizes);
		if (len == 2)
			sort_two(&moves, lst_a, &lst_b);
		else
			sort_three(&moves, lst_a, &lst_b);
		conquer(&moves, lst_a, &lst_b, &part_sizes);
	}
	ft_lstclear(&part_sizes, &del_int_content);
	return (moves);
}
