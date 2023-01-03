/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize_moves2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:40:37 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/03 16:53:34 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	remove_both(t_list **move, t_list **to_compare)
{
	(*move)->data = "x";
	(*to_compare)->data = "x";
	return (1);
}

static int	check_pa_pb(t_list **move, t_list **to_compare)
{
	int	moved;

	moved = 0;
	if (!ft_strncmp((*move)->data, "pa", 2))
	{
		if (!ft_strncmp((*to_compare)->data, "pb", 2))
			moved = remove_both(move, to_compare);
	}
	else if (!ft_strncmp((*move)->data, "pb", 2))
	{
		if (!ft_strncmp((*to_compare)->data, "pa", 2))
			moved = remove_both(move, to_compare);
	}
	return (moved);
}

static int	check_ra_rra_rb_rrb(t_list **move, t_list **to_compare)
{
	int	moved;

	moved = 0;
	if (!ft_strncmp((*move)->data, "ra", 2))
	{
		if (!ft_strncmp((*to_compare)->data, "rra", 3))
			moved = remove_both(move, to_compare);
	}
	else if (!ft_strncmp((*move)->data, "rb", 2))
	{
		if (!ft_strncmp((*to_compare)->data, "rrb", 3))
			moved = remove_both(move, to_compare);
	}
	else if (!ft_strncmp((*move)->data, "rra", 2))
	{
		if (!ft_strncmp((*to_compare)->data, "ra", 3))
			moved = remove_both(move, to_compare);
	}
	else if (!ft_strncmp((*move)->data, "rrb", 2))
	{
		if (!ft_strncmp((*to_compare)->data, "rb", 3))
			moved = remove_both(move, to_compare);
	}
	return (moved);
}

int	check_double_removal(t_list **move, t_list **to_compare)
{
	int	moved;

	moved = 0;
	if (!ft_strncmp((*move)->data, "pa", 2) || \
		!ft_strncmp((*move)->data, "pb", 2))
	{
		moved = check_pa_pb(move, to_compare);
	}
	else if (!ft_strncmp((*move)->data, "ra", 2) || \
		!ft_strncmp((*to_compare)->data, "rra", 3) || \
		!ft_strncmp((*to_compare)->data, "rrb", 3) || \
		!ft_strncmp((*to_compare)->data, "rb", 3))
	{
		moved = check_ra_rra_rb_rrb(move, to_compare);
	}
	return (moved);
}