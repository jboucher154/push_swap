/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:04:57 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/04 13:48:32 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_compared(t_list *temp)
{
	t_list	*to_compare;

	to_compare = temp->next;
	if (to_compare && !ft_strncmp((to_compare)->data, "x", 1))
	{
		while (to_compare && !ft_strncmp(to_compare->data, "x", 1))
			to_compare = to_compare->next;
	}
	return (to_compare);
}

static int	check_extra_moves(t_list **moves)
{
	t_list	*temp;
	t_list	*to_compare;
	int		moved;

	temp = *moves;
	moved = 0;
	while (temp && temp->next)
	{
		if (!ft_strncmp(temp->data, "x", 1))
		{
			while (temp && !ft_strncmp(temp->data, "x", 1))
				temp = temp->next;
		}
		if (!temp)
			break ;
		to_compare = get_compared(temp);
		if (!temp || !to_compare)
			break ;
		moved += check_double_removal(&temp, &to_compare);
		temp = temp->next;
	}
	return (moved);
}
//add check for null moves, exit program if found...

void	sanitize_moves(t_list **moves)
{
	int		moved;

	if (!moves || !*moves)
		return ;
	moved = 1;
	while (moved)
	{
		moved = check_extra_moves(moves);
	}
}
