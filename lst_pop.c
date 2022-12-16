/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:22:59 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/15 13:36:54 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pop_head(t_list **to_remove)
{
	if ((*to_remove)->next != NULL)
	{
		(*to_remove)->next->previous = NULL;
		(*to_remove) = (*to_remove)->next;
	}
}

static void	pop_mid(t_list **to_remove)
{
		(*to_remove)->previous->next = (*to_remove)->next;
		(*to_remove)->next->previous = (*to_remove)->previous;
}

static void	pop_tail(t_list **to_remove)
{
	(*to_remove)->previous->next = NULL;
}

t_list	*lst_pop(t_list **to_remove)
{
	t_list	*popped;

	popped = *to_remove;
	if (!to_remove || !popped)
		return (NULL);
	if (popped->previous == NULL)
		pop_head(to_remove);
	else if (popped->next != NULL)
		pop_mid(to_remove);
	else
		pop_tail(to_remove);
	popped->next = NULL;
	popped->previous = NULL;
	return (popped);
}
