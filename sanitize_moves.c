/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:04:57 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/21 15:17:04 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	remove_both(t_list **temp)
{
	t_list	*popped;

	ft_printf("remove both\n");//
	print_str_list(*temp);	
	if (!temp || !(*temp))
		return (0);
	if (!(*temp)->next->next)
	{
		*temp = NULL;
		return (-10);
	}
	else
	{
		popped = lst_pop(temp);
		ft_printf("POPPED: %s\n", popped->data);//
		ft_lstdelone(popped, &del_str_content);
		popped = lst_pop(temp);
		ft_printf("POPPED: %s\nTEMP LIST:\n", popped->data);//
		ft_lstdelone(popped, &del_str_content);
		print_str_list(*temp);
		return (1);
	}
}

int	remove_one(t_list **temp, char *replace_with)
{
	t_list	*to_pop;
	ft_printf("remove one\n");
	t_list	*popped;

	if (!temp || !*temp)
		return (0);
	to_pop = (*temp)->next;
	popped = lst_pop(&to_pop);
	ft_lstdelone(popped, &del_str_content);
	(*temp)->data = replace_with;
	return (1);
}

int	check_double_removal(t_list **temp_moves, char *current, char *next)
{
	int	moved;
	ft_printf("dbl removal\n");//
	moved = 0;
	if (!ft_strncmp(current, "pa", 2))
	{
		if (!ft_strncmp(next, "pb", 2))
			moved = remove_both(temp_moves);
	}
	else if (!ft_strncmp(current, "pb", 2))
	{
		if (!ft_strncmp(next, "pa", 2))
			moved = remove_both(temp_moves);
	}
	else if (!ft_strncmp(current, "ra", 2))
	{
		if (!ft_strncmp(next, "rra", 3))
			moved = remove_both(temp_moves);
	}
	else if (!ft_strncmp(current, "rb", 2))
	{
		if (!ft_strncmp(next, "rrb", 3))
			moved = remove_both(temp_moves);
	}
	return (moved);
}

int	check_single_removal(t_list **temp_moves, char *current, char *next)
{
	int	moved;

	moved = 0;
	if (!ft_strncmp(current, "rr", 2))
	{
		if (!ft_strncmp(next, "rra", 3))
			moved = remove_one(temp_moves, "rb");
		else if (!ft_strncmp(next, "rrb", 3))
			moved = remove_one(temp_moves, "ra");
	}
	else if (!ft_strncmp(current, "rrr", 3))
	{
		if (!ft_strncmp(next, "ra", 2))
			moved = remove_one(temp_moves, "rrb");
		else if (!ft_strncmp(next, "rb", 2))
			moved = remove_one(temp_moves, "rra");
	}
	return (moved);
}

void	sanitize_moves(t_list **moves)
{
	t_list *temp_moves;
	char	*current;
	char	*next;
	int		moved;

	if (!moves || !*moves)
		return ;
	temp_moves = *moves;
	while (temp_moves && temp_moves->next)
	{
		ft_printf("\nMOVES at begin of sanitaize loop:\n");//
		print_str_list(*moves);
		ft_printf("\ntemp at begin of sanitaize loop:\n%s\n", temp_moves->data);//
		moved = 0;
		current = temp_moves->data;
		next = temp_moves->next->data;
		moved  = check_double_removal(&temp_moves, current, next);
		if (moved == 0)
			moved = check_single_removal(&temp_moves, current, next);
		if (moved == 0)
			temp_moves = temp_moves->next;
		if (temp_moves == NULL && moved < 0)
		{
			ft_lstclear(moves, &del_str_content);
			return ;
		}
	}
}