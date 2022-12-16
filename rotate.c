/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:58:35 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/16 12:19:54 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// for ra rb moves
char	*ra(t_list **head)
{
	t_list	*popped;

	if (!head || !(*head))
		return (NULL);
	popped = lst_pop(head);
	ft_lstadd_back(head, popped);
	return ("ra");
}

char	*rb(t_list **head)
{
	t_list	*popped;

	if (!head || !(*head))
		return (NULL);
	popped = lst_pop(head);
	ft_lstadd_back(head, popped);
	return ("rb");
}
//fot rr (ra, rb)
char	*rr(t_list **head_a, t_list **head_b)
{
	if (!head_a || !head_b)
		return (NULL);
	ra(head_a);
	rb(head_b);
	return ("rr");
}