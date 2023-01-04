/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:12:58 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/04 11:13:26 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//may not need this one
void	check_swaps_b(t_list **moves, t_list **lst_b)
{
	if (lst_b == NULL || *lst_b == NULL)
		return ;
	if ((*lst_b)->next && *((int *)(*lst_b)->data) < \
		*((int *)(*lst_b)->next->data))
		add_move(moves, sb(lst_b));
}

int	add_move(t_list **moves, char *move)
{
	t_list	*new;

	new = NULL;
	while (!new)
		new = ft_lstnew(move);
	ft_lstadd_back(moves, new);
	return (1);
}

int	check_if_sorted(t_list *head)
{
	int		len;
	t_list	*temp;

	if (!head)
		return (0);
	temp = head;
	len = ft_lstsize(temp);
	while (temp->next && ((*(int *)temp->data) <= (*(int *)temp->next->data)))
	{
		len--;
		temp = temp->next;
	}
	if (len == 1)
		return (1);
	return (0);
}

int	check_if_revsorted(t_list *head, int len)
{
	t_list	*temp;

	if (!head)
		return (0);
	temp = head;
	while (len && temp->next && ((*(int *)temp->data) >= \
		(*(int *)temp->next->data)))
	{
		len--;
		temp = temp->next;
	}
	if (len == 1)
		return (1);
	return (0);
}

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}