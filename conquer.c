/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:06:14 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/27 17:55:39 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//can I make this recursive until the partition is down to len of 1?
//send to first half, then recalculate the pivot point, send the next half of that, etc. until it is len one, then just add that one... or len of two?
//make a partition handler... carry rotation count, total partition size, evaluated number, sent number....
void	send_higher_values(t_list **moves, t_list **lst_a, t_list **lst_b, int *rot_piv_eva_sen_siz)
{
	while (rot_piv_eva_sen_siz[4])//?? what condition here?
	{
		
	}
}

void	handle_partition(t_list **moves, t_list **lst_a, t_list **lst_b, int part_size)
{
	// int	rot_count;
	// int	pivot;
	// int	evaled_sent[2];
	int	rot_piv_eva_sen_siz[5];

	// rot_count = 0;
	// evaled_sent[0] = 0;
	// evaled_sent[1] = 0;
	// pivot = find_mean(*lst_b, part_size);

	rot_piv_eva_sen_siz[0] = 0;
	rot_piv_eva_sen_siz[1] = find_mean(*lst_b, part_size);
	rot_piv_eva_sen_siz[2] = 0;
	rot_piv_eva_sen_siz[3] = 0;
	rot_piv_eva_sen_siz[4] = part_size;

	ft_printf(" C PIVOT : %i\n", rot_piv_eva_sen_siz[1]);
	//send all values greater than pivot to a

	send_higher_values(moves, lst_a, lst_b, rot_piv_eva_sen_siz);
	// while (evaled_sent[0] < part_size)
	// {
	// 	if ((*lst_b) && *((int *)(*lst_b)->data) > pivot)
	// 	{
	// 		add_move(moves, pa(lst_a, lst_b));
	// 		evaled_sent[1]++;
	// 		if ((*lst_a)->next && *((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data))
	// 			add_move(moves, sa(lst_a)); //may not be able to ss as may violate the partition in b
	// 	}
	// 	else
	// 	{
	// 		add_move(moves, rb(lst_b));
	// 		rot_count++;
	// 	}
	// 	evaled_sent[0]++;
	// }
	// part_size = part_size - evaled_sent[1];
	// evaled_sent[0] = 0;
	// 	ft_printf("\nBEFORE SENDING VALUES LOWER THAN PIVOT\n");
	// 	ft_printf("\nSTACK A\n");//
	// 	print_int_list(*lst_a);//
	// 	ft_printf("STACK B\n");//
	// 	print_int_list(*lst_b);//

	// //send all the values that are = or lower than pivot
	// while ((*lst_b) && evaled_sent[0] < part_size)
	// {
	// 	if (rot_count)
	// 	{
	// 		add_move(moves, rrb(lst_b));
	// 		rot_count--;
	// 	}
	// 	else
	// 	{	//move and check placement...
	// 		add_move(moves, pa(lst_a, lst_b));
	// 		evaled_sent[0]++; //perhaps unecessary
	// 		if ((*lst_a)->next && *((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data))
	// 		{
	// 			if (evaled_sent[0] - part_size >= 2 && (*lst_b) && (*lst_b)->next && *((int *)(*lst_b)->data) < *(int *)(*lst_b)->next->data)
	// 				add_move(moves, ss(lst_a, lst_b));
	// 			else
	// 				add_move(moves, sa(lst_a));
	// 		}
	// 	}
	// }
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
			ft_printf("I'M ALLREADY SORTED\n");//
			while (size)
			{
				add_move(moves, pa(lst_a, lst_b));
				size--;
			}
		}
		else
			handle_partition(moves, lst_a, lst_b, size);
		//delete had node from part_sizes...
		popped = lst_pop(part_sizes);
		free(popped);
	}
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