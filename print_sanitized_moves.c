/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sanitized_moves.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:18:14 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/22 10:47:56 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_extra_moves(t_list **moves)
{
	char	*current;
	char	*next;

	current = (*moves)->data;
	next = (*moves)->next->data;
	if (!ft_strncmp(current, "pa", 2) && !ft_strncmp(next, "pb", 2))
			return (2);
	else if (!ft_strncmp(current, "pb", 2) && !ft_strncmp(next, "pa", 2))
		return (2);
	else if (!ft_strncmp(current, "ra", 2) && !ft_strncmp(next, "rra", 3))
		return (2); 
	else if (!ft_strncmp(current, "rb", 2))
		return (2); 
	else if (!ft_strncmp(current, "rr", 2) && !ft_strncmp(next, "rra", 3))
		return (ft_printf("rb"));
	else if (!ft_strncmp(current, "rr", 2) && !ft_strncmp(next, "rrb", 3))
		return (ft_printf("ra"));
	else if (!ft_strncmp(current, "rrr", 3) && !ft_strncmp(next, "ra", 2))
		return (ft_printf("rrb"));
	else if (!ft_strncmp(current, "rrr", 3) && !ft_strncmp(next, "rb", 2))
		return (ft_printf("rra"));
	else 
		ft_printf("%s\n", (*moves)->data);
	return (1);
}

void	check_combine_moves(t_list **moves)
{
	char	*current;
	char	*next;

	current = (*moves)->data;
	next = (*moves)->next->data;
}

void	print_sanitized_moves(t_list **moves)
{
	t_list	*temp;
	int		check;

	if (!moves || !(*moves))
		return ;
	temp = *moves;
	while (temp != NULL && temp->next != NULL)
	{
		check = check_extra_moves(&temp);
		if (check == 1)
			temp = temp->next;
		else
		{
			// if (temp->next->next == NULL)
			// 	break ;
			// else
			temp = temp->next->next;
		}
	}
	if (temp != NULL)
		ft_printf("%s\n", temp->data);
}