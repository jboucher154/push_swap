/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:59:34 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/16 12:19:37 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//for rra rrb
char	*rra(t_list **head)
{
	t_list	*popped;
	t_list	*to_pop;

	if (!head || !(*head))
		return (NULL);
	to_pop = ft_lstlast(*head);
	popped = lst_pop(&to_pop);
	ft_lstadd_front(head, popped);
	return ("rra");
}

char	*rrb(t_list **head)
{
	t_list	*popped;
	t_list	*to_pop;

	if (!head || !(*head))
		return (NULL);
	to_pop = ft_lstlast(*head);
	popped = lst_pop(&to_pop);
	ft_lstadd_front(head, popped);
	return ("rrb");
}

//for rrr
char	*rrr(t_list **head_a, t_list **head_b)
{
	if (!head_a || !head_b)
		return (NULL);
	ra(head_a);
	rb(head_b);
	return (rrr);
}