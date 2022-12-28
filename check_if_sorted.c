/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:38:58 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/28 17:21:58 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (len && temp->next && ((*(int *)temp->data) >= (*(int *)temp->next->data)))
	{
		len--;
		temp = temp->next;
	}
	if (len == 1)
		return (1);
	return (0);
}
