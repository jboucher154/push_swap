/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:06:14 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/28 17:14:35 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//can I make this recursive until the partition is down to len of 1?
//send to first half, then recalculate the pivot point, send the next half of that, etc. until it is len one, then just add that one... or len of two?
//make a partition handler... carry rotation count, total partition size, evaluated number, sent number....
void	unrotate_b(t_list **moves, t_list **lst_b, int rotation)
{
	while (rotation)
		rotation -= add_move(moves, rrb(lst_b));
		
	// ft_printf("STACK B\n");//
	// print_int_list(*lst_b);//
}

// void	unrotate_a(t_list **moves, t_list **lst_a, int rotation)
// {
// 	while (rotation)
// 		rotation -= add_move(moves, rra(lst_a));
// }

void	send_higher_values(t_list **moves, t_list **lst_a, t_list **lst_b, int part_size)
{
	int	rotation;
	int	pivot;
	int	evaled;
	int	sent;

	pivot = find_mean(*lst_b, part_size);
	rotation = 0;
	evaled = 0;
	sent = 0;
	
	// ft_printf(" C PIVOT : %i\n", pivot); //
	// ft_printf(" C PART SIZE : %i\n", part_size); //
	// ft_printf("\nSTACK A\n");//
	// print_int_list(*lst_a);//
	if (part_size == 1)
	{
		sent += push_to_a(moves, lst_a, lst_b);
		return ;
	}
	while (evaled < part_size)//?? what condition here?
	{
		if ((*lst_b) && *((int *)(*lst_b)->data) > pivot)
		{
			if (part_size - evaled > 2 && (*lst_b)->next && *((int *)(*lst_b)->next->data) > pivot && (*((int *)(*lst_b)->next->data) > *((int *)(*lst_b)->data)))
				add_move(moves, sb(lst_b)); //
			sent += push_to_a(moves, lst_a, lst_b);
		}
		else
			rotation += add_move(moves, rb(lst_b));
		evaled++;
	}
	if (part_size - sent > 0)
	{
		unrotate_b(moves, lst_b, rotation);
		send_higher_values(moves, lst_a, lst_b,(part_size - sent));
	}
}

void	handle_partition(t_list **moves, t_list **lst_a, t_list **lst_b, int part_size)
{
	if (part_size == 2)
	{
		push_to_a(moves, lst_a, lst_b);
		push_to_a(moves, lst_a, lst_b);
	}
	else if (part_size > 2)
	{
		// ft_printf("\nTOP OF SEND HIGHER VALS\n");
		// ft_printf("\nSTACK A\n");//
		// print_int_list(*lst_a);//
		// ft_printf("STACK B\n");//
		// print_int_list(*lst_b);//
		send_higher_values(moves, lst_a, lst_b, part_size);
	}
}

void	conquer(t_list **moves, t_list **lst_a, t_list **lst_b, t_list **part_sizes)
{
	t_list *popped;
	int		size;
		
	while (part_sizes && *part_sizes)
	{
		size = *(int *)(*part_sizes)->data;
		if (size == 1 || check_if_revsorted(*lst_b, size))
		{
			// ft_printf("I'M ALLREADY SORTED\n");//
			while (size)
			{
				add_move(moves, pa(lst_a, lst_b));
				check_swaps_a(moves, lst_a);
				size--;
			}
		}
		else
			handle_partition(moves, lst_a, lst_b, size);
		popped = lst_pop(part_sizes);
		free(popped);
	}
	if (part_sizes)
		ft_lstclear(part_sizes, &del_int_content);
}

		// ft_printf("\nTOP OF CONQUER\n");
		// ft_printf("\nSTACK A\n");//
		// print_int_list(*lst_a);//
		// ft_printf("STACK B\n");//
		// print_int_list(*lst_b);//
		// // ft_printf("moves\n");//
		// // print_str_list(*moves);//
		// ft_printf("PARTION SIZES\n");//
		// print_int_list(*part_sizes);//
