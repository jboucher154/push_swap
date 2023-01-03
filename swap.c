/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:31:46 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/03 16:53:10 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// for sa and sb moves
char	*sa(t_list **head)
{
	int	*temp;

	if (!head)
		return (NULL);
	if (head && (*head)->next)
	{
		temp = (int *)(*head)->data;
		(*head)->data = (*head)->next->data;
		(*head)->next->data = temp;
	}
	return ("sa");
}

char	*sb(t_list **head)
{
	int	*temp;

	if (!head)
		return (NULL);
	if (head && (*head)->next)
	{
		temp = (int *)(*head)->data;
		(*head)->data = (*head)->next->data;
		(*head)->next->data = temp;
	}
	return ("sb");
}

//for ss move (sa and sb)
char	*ss(t_list **head_a, t_list **head_b)
{
	if (!head_a || !head_b)
		return (NULL);
	sa(head_a);
	sb(head_b);
	return ("ss");
}
