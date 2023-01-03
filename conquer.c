/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:06:14 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/03 18:20:19 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	unrotate_b(t_list **moves, t_list **lst_b, int rotation)
{
	while (rotation)
		rotation -= add_move(moves, rrb(lst_b));
}

static int	send_rot(t_list **ms, t_list **lst_a, t_list **lst_b, int *snt_size)
{
	int	pivot;
	int	rotation;
	int	evaled;

	pivot = find_mean(*lst_b, snt_size[1]);
	rotation = 0;
	evaled = 0;
	while (evaled < snt_size[1])
	{
		if ((*lst_b) && *((int *)(*lst_b)->data) > pivot)
		{
			if (snt_size[1] - evaled > 2 && (*lst_b)->next && \
				*((int *)(*lst_b)->next->data) > pivot && \
				(*((int *)(*lst_b)->next->data) > *((int *)(*lst_b)->data)))
				add_move(ms, sb(lst_b));
			snt_size[0] += push_to_a(ms, lst_a, lst_b);
		}
		else if (!more_to_move(lst_b, pivot, (snt_size[1] - evaled)))
			break ;
		else
			rotation += add_move(ms, rb(lst_b));
		evaled++;
	}
	return (rotation);
}

static void	send_highs(t_list **ms, t_list **lst_a, t_list **lst_b, int part_s)
{
	int	rotation;
	int	sent_size[2];

	rotation = 0;
	sent_size[0] = 0;
	sent_size[1] = part_s;
	if (part_s == 1)
	{
		sent_size[0] += push_to_a(ms, lst_a, lst_b);
		return ;
	}
	rotation += send_rot(ms, lst_a, lst_b, sent_size);
	if (part_s - sent_size[0] > 0)
	{
		unrotate_b(ms, lst_b, rotation);
		send_highs(ms, lst_a, lst_b, (part_s - sent_size[0]));
	}
}

static void	handle_part(t_list **ms, t_list **lst_a, t_list **lst_b, int part_s)
{
	if (part_s == 2)
	{
		push_to_a(ms, lst_a, lst_b);
		push_to_a(ms, lst_a, lst_b);
	}
	else if (part_s > 2)
	{
		send_highs(ms, lst_a, lst_b, part_s);
	}
}

void	conquer(t_list **mves, t_list **lst_a, t_list **lst_b, t_list **part_ss)
{
	t_list	*temp_part;
	int		size;

	temp_part = *part_ss;
	while (temp_part)
	{
		size = *(int *)temp_part->data;
		if (size == 1 || check_if_revsorted(*lst_b, size))
		{
			while (size)
			{
				push_to_a(mves, lst_a, lst_b);
				size--;
			}
		}
		else
			handle_part(mves, lst_a, lst_b, size);
		temp_part = temp_part->next;
	}
}
