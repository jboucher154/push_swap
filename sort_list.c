/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:59:43 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/27 12:45:10 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_moves(t_list **moves, t_list **lst_a, t_list **lst_b);
void	check_next_placement(t_list **moves, t_list **lst_a, t_list **lst_b);

void	check_unrotate_placements(t_list **moves, t_list **lst_a, t_list **lst_b, int rot_count)
{
	// t_list	*last;
	while (rot_count)
	{
		ft_printf("\nUNROTATED PLACEMENT\n");
		ft_printf("\nSTACK A\n");//
		print_int_list(*lst_a);//
		ft_printf("STACK B\n");//
		print_int_list(*lst_b);//
		// last = ft_lstlast(*lst_a);
		if (*((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data)) //a need to move, check if b needs too
		{
			ft_printf("\nNeed A swap\n");
			check_swaps_a(moves, lst_a, lst_b);
		}
		else if (*lst_b && (*lst_b)->next != NULL) //only b needs to move
		{
			ft_printf("\nNeed B swap\n");
			if ((*lst_b)->next && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data))
				add_move(moves, sb(lst_b));
		}
		add_move(moves, rra(lst_a));
		rot_count--;
				if (*((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data)) //a need to move, check if b needs too
		{
			ft_printf("\nNeed A swap\n");
			check_swaps_a(moves, lst_a, lst_b);
		}
		else if (*lst_b && (*lst_b)->next != NULL) //only b needs to move
		{
			ft_printf("\nNeed B swap\n");
			if ((*lst_b)->next && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data))
				add_move(moves, sb(lst_b));
		}
		// if (last && (*lst_b) && (*(int *)last->data) > *((int *)(*lst_b)->data)) //added
		// {
		// 	add_move(moves, rra(lst_a));//added
		// 	rot_count--;
		// }
		if (lst_b && *lst_b)
			check_next_placement(moves, lst_a, lst_b);
	}
}

void	needs_rotation(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	int	rot_count;
	ft_printf("\nNEEDS ROTATION\n");
	ft_printf("\nSTACK A\n");//
	print_int_list(*lst_a);//
	ft_printf("STACK B\n");//
	print_int_list(*lst_b);//
	rot_count = 0;
	while ((!(*((int *)(*lst_b)->data) <= *((int *)(*lst_a)->data)) || \
	 !(*((int *)(*lst_b)->data) <= *((int *)(*lst_a)->next->data))))
	{
		add_move(moves, ra(lst_a));
		rot_count++;
	}
	add_move(moves, pa(lst_a, lst_b));
	//check placements while recombining...
	check_unrotate_placements(moves, lst_a, lst_b, rot_count);
}

void	check_next_placement(t_list **moves, t_list **lst_a, t_list **lst_b) //remove int param
{
	if (!lst_b || !(*lst_b))
		return ;
	ft_printf("TOP OF CHECK NEXT PLACEMENT!\n");
	// ft_printf("\nSTACK A\n");//
	// print_int_list(*lst_a);//
	// ft_printf("STACK B\n");//
	// print_int_list(*lst_b);//
	if (*((int *)(*lst_b)->data) < *((int *)(*lst_a)->data)) //if it fits on top OKAY
		add_move(moves, pa(lst_a, lst_b));
	else if (*((int *)(*lst_b)->data) < *((int *)(*lst_a)->next->data)) //if it fits between top and next OKAY
		add_move(moves, pa(lst_a, lst_b));
	else
		needs_rotation(moves, lst_a, lst_b);
}

void	recombine(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	ft_printf("\nTOP of recombine\n");//
	ft_printf("\nSTACK A\n");//
	print_int_list(*lst_a);//
	ft_printf("STACK B\n");//
	print_int_list(*lst_b);//
	if (*((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data)) //a need to move, check if b needs too
	{
		// ft_printf("\nA NEEDS SWAP\n");//
		check_swaps_a(moves, lst_a, lst_b);
		recombine(moves, lst_a, lst_b);
	}
	else if ((*lst_b) && (*lst_b)->next != NULL && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data)) //only b needs to move
	{
		// ft_printf("\nB NEEDS SWAP\n");//
		add_move(moves, sb(lst_b));
		recombine(moves, lst_a, lst_b);
	}
	else if ((*lst_b) != NULL) //push to a
	{
		check_next_placement(moves, lst_a, lst_b);
		recombine(moves, lst_a, lst_b);
	}
	else
		return ;
}

void	make_moves(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a)->next->next == NULL) //is len 2
	{
		ft_printf("TO RECOMBINE!\n");
		ft_printf("\nSTACK A\n");//
		print_int_list(*lst_a);//
		ft_printf("STACK B\n");//
		print_int_list(*lst_b);//
		recombine(moves, lst_a, lst_b);
		return ;
	}
	if ((*lst_a)->next != NULL && *((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data)) //a need to move, check if b needs too
	{
		check_swaps_a(moves, lst_a, lst_b);
		make_moves(moves, lst_a, lst_b);
	}
	else if ((*lst_b) && (*lst_b)->next != NULL && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data)) //only b needs to move
	{
		check_swaps_b(moves, lst_a, lst_b);
		make_moves(moves, lst_a, lst_b);
	}
	else //push to b or recombine
	{
		add_move(moves, pb(lst_b, lst_a));
		make_moves(moves, lst_a, lst_b);
	}
}

// t_list	*sort_list(t_list **lst_a)
// {
// 	t_list	*lst_b;
// 	t_list	*moves;
// 	t_list	*new;

// 	lst_b = NULL;
// 	moves = NULL;
// 	if (!lst_a && !(*lst_a))
// 		return (NULL);
// 	if ((*lst_a)->next == NULL)
// 		return (moves);
// 	else
// 		make_moves(&moves, lst_a, &lst_b);
// 	return (moves);
// }

// void	make_moves(t_list **moves, t_list **lst_a, t_list **lst_b)
// {
// 	int	ab_len[2];
	
// 	ab_len[0] = ft_lstsize(*lst_a);
// 	ab_len[1] = ft_lstsize(*lst_b);
// 	if (ab_len[0] == 2)
// 	{
// 		// ft_printf("TO RECOMBINE!\n");
// 		// ft_printf("\nSTACK A\n");//
// 		// print_int_list(*lst_a);//
// 		// ft_printf("STACK B\n");//
// 		// print_int_list(*lst_b);//
// 		recombine(moves, lst_a, lst_b);
// 		return ;
// 	}
// 	if (ab_len[0] > 1 && *((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data)) //a need to move, check if b needs too
// 	{
// 		check_swaps_a(moves, lst_a, lst_b, ab_len);
// 		make_moves(moves, lst_a, lst_b);
// 	}
// 	else if (ab_len[1] > 1 && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data)) //only b needs to move
// 	{
// 		check_swaps_b(moves, lst_a, lst_b, ab_len);
// 		make_moves(moves, lst_a, lst_b);
// 	}
// 	else //push to b or recombine
// 	{
// 		add_move(moves, pb(lst_b, lst_a));
// 		make_moves(moves, lst_a, lst_b);
// 	}
// }