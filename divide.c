/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:06:26 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/04 12:35:41 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_move(t_list **moves, t_list **lst_a, int pivot)
{
	int		len;
	int		location;
	t_list	*temp;

	len = ft_lstsize(*lst_a);
	location = 0;
	temp = *lst_a;
	while (temp)
	{
		location++;
		if (*(int *)temp->data < pivot)
			break ;
		temp = temp->next;
	}
	if (temp == NULL)
		return (0);
	else if (location <= len / 2 || (len % 2 != 0 && location <= (len + 1) / 2))
		return (rotate_a(moves, lst_a, location - 1));
	else
		return (rev_rotate_a(moves, lst_a, len - location + 1));
}

int	partition(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	int	len;
	int	size;
	int	pivot;
	int	remaining;

	len = ft_lstsize(*lst_a);
	remaining = 1;
	size = 0;
	if (len == 3)
		return (size);
	pivot = find_q_mean(*lst_a, len);
	while (len > 3 && remaining)
	{
		if (*(int *)(*lst_a)->data < pivot)
		{
			add_move(moves, pb(lst_b, lst_a));
			size++;
			len--;
		}
		else
			remaining = find_next_move(moves, lst_a, pivot);
	}
	return (size);
}

void	divide(t_list **moves, t_list **lst_a, t_list **lst_b, t_list **part_ss)
{
	t_list	*new;
	int		size;

	size = 1;
	while (size)
	{
		size = partition(moves, lst_a, lst_b);
		if (size == 0)
			break ;
		new = ft_lstnew(make_int_content(size));
		if (!new)
		{
			ft_lstclear(lst_a, &del_int_content);
			ft_lstclear(lst_b, &del_int_content);
			ft_lstclear(moves, &del_str_content);
			ft_lstclear(part_ss, &del_int_content);
			error();
		}
		ft_lstadd_front(part_ss, new);
	}
}
