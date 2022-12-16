/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:57:55 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/16 12:21:27 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// for pa and pb moves
char	*pa(t_list **head_a, t_list **head_b)
{
	t_list	*popped;

	if (!head_a || !head_b || !(*head_b))
		return (NULL);
	popped = lst_pop(head_b);
	ft_lstadd_front(head_a, popped);
	return ("pa");
}

char	*pb(t_list **head_b, t_list **head_a)
{
	t_list	*popped;

	if (!head_b || !head_a || !(*head_a))
		return (NULL);
	popped = lst_pop(head_a);
	ft_lstadd_front(head_b, popped);
	return ("pb");
}
