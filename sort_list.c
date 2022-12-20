/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:59:43 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/20 18:20:29 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_moves(t_list **moves, t_list **lst_a, t_list **lst_b);


void	add_move(t_list **moves, char *move)
{
		t_list	*new;

	new = ft_lstnew(move);
	if (!new)
		return ; //exit?
	ft_lstadd_back(moves, new);
}

void	check_swaps_a(t_list **moves, t_list **lst_a, t_list **lst_b, int *ab_len)
{
	if (ab_len[0] > 1 && *((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data)) //a need to move, check if b needs too
	{
		if (ab_len[1] > 1 && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data))
			add_move(moves, ss(lst_a, lst_b));
		else //just swap a
			add_move(moves, sa(lst_a));
	}
}

void	check_swaps_b(t_list **moves, t_list **lst_a, t_list **lst_b, int *ab_len)
{
	if (ab_len[1] > 1 && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data)) //only b needs to move
	{
		if (ab_len[1] == 2 && ab_len[0] > 2) // reverse rotate if b is 2, so get extra movement from a
		{
			add_move(moves, rrr(lst_a, lst_b));
		}
		else //just move b
		{
			add_move(moves, sb(lst_b));
		}
	}
}

void	recombine(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	int	ab_len[2];
	ft_printf("TOP OF RECOMMBINE!\n");
	ft_printf("\nSTACK A\n");//
	print_int_list(*lst_a);//
	ft_printf("STACK B\n");//
	print_int_list(*lst_b);//
	
	ab_len[0] = ft_lstsize(*lst_a);
	ab_len[1] = ft_lstsize(*lst_b);
	if (*((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data)) //a need to move, check if b needs too
	{
		// check_swaps_a(moves, lst_a, lst_b, ab_len);
		// recombine(moves, lst_a, lst_b);
		if (ab_len[1] > 1 && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data))
		{
				add_move(moves, ss(lst_a, lst_b));
				recombine(moves, lst_a, lst_b);
		}
		else //just swap a
		{
			add_move(moves, sa(lst_a));
			recombine(moves, lst_a, lst_b);
		}
	}
	else if (ab_len[1] > 1 && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data)) //only b needs to move
	{
		// check_swaps_b(moves, lst_a, lst_b, ab_len);
		// if (b_len == 2) // reverse rotate if b is 2, so get extra movement from a
		// {
		// 	add_move(moves, rrb(lst_b));
		// 	recombine(moves, lst_a, lst_b);
		// }
		// else //just move b
		// {
		add_move(moves, sb(lst_b));
		recombine(moves, lst_a, lst_b);
		// }
	}
	else if (ab_len[1] > 0) //push to a
	{
		add_move(moves, pa(lst_a, lst_b));
		recombine(moves, lst_a, lst_b);
	}
	else
		return ;
}

void	make_moves(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	int	ab_len[2];
	
	ab_len[0] = ft_lstsize(*lst_a);
	ab_len[1] = ft_lstsize(*lst_b);
	if (ab_len[0] == 2)
	{
		// ft_printf("TO RECOMBINE!\n");
		// ft_printf("\nSTACK A\n");//
		// print_int_list(*lst_a);//
		// ft_printf("STACK B\n");//
		// print_int_list(*lst_b);//
		recombine(moves, lst_a, lst_b);
		return ;
	}
	if (ab_len[0] > 1 && *((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data)) //a need to move, check if b needs too
	{
		check_swaps_a(moves, lst_a, lst_b, ab_len);
		make_moves(moves, lst_a, lst_b);
	}
	else if (ab_len[1] > 1 && *((int *)(*lst_b)->data) < *((int *)(*lst_b)->next->data)) //only b needs to move
	{
		check_swaps_b(moves, lst_a, lst_b, ab_len);
		make_moves(moves, lst_a, lst_b);
	}
	else//push to b or recombine
	{
		add_move(moves, pb(lst_b, lst_a));
		make_moves(moves, lst_a, lst_b);
	}
}

t_list	*sort_list(t_list **lst_a)
{
	t_list	*lst_b;
	t_list	*moves;
	t_list	*new;

	lst_b = NULL;
	moves = NULL;
	if (ft_lstsize(*lst_a) == 1)
		return (moves);
	else
		make_moves(&moves, lst_a, &lst_b);
	return (moves);
}

// t_list	*sort_list(t_list *lst_a)
// {
// 	t_list	*lst_b;
// 	t_list	*moves;
// 	t_list	*new;
// 	int		len;
// 	int 	i;

// 	lst_b = NULL;
// 	moves = NULL;
// 	i = 0;
// 	len = ft_lstsize(lst_a);
// 	if (len == 1)
// 		return (moves);//list is already sorted
// 	else
// 	{
// 		while (i < len / 2)
// 		{
// 			new = ft_lstnew(pb(&lst_b, &lst_a));
// 			if (new)
// 				ft_lstadd_back(&moves, new);
// 			else
// 			{
// 				ft_lstclear(&lst_a, &del_int_content);
// 				ft_lstclear(&lst_b, &del_int_content);
// 				ft_lstclear(&moves, &del_str_content);
// 				return (NULL);
// 				//exit??;
// 			}
// 			i++;
// 		}
// 		ft_printf("MOVES\n");
// 		print_str_list(moves);
// 		ft_printf("STACK A\n");
// 		print_int_list(lst_a);
// 		ft_printf("STACK B\n");
// 		print_int_list(lst_b);
// 		make_move(&moves, &lst_a, &lst_b);
// 		ft_printf("--------AFTER MAKE MOVES---------\n");
// 		ft_printf("MOVES\n");
// 		print_str_list(moves);
// 		ft_printf("STACK A\n");
// 		print_int_list(lst_a);
// 		ft_printf("STACK B\n");
// 		print_int_list(lst_b);
// 		//otherwse start the sorting?
// 	}
// 	//free other lists before return?
// 	// ft_lstclear(&lst_a, &del_int_content);
// 	// ft_lstclear(&lst_b, &del_int_content);
// 	return (moves);
// }

	// ft_printf("\nSTACK A\n");//
	// print_int_list(*lst_a);//
	// ft_printf("STACK B\n");//
	// print_int_list(*lst_b);//
	// ft_printf("len of b: %i\n", ab_len[1]);

// ft_printf("\ngo to recombine STACK A\n");//
// print_int_list(*lst_a);//
// ft_printf("go to recombine STACK B\n");//
// print_int_list(*lst_b);//

// ft_printf("at begiing of make moves STACK A\n");//
// 		print_int_list(*lst_a);//
// 		ft_printf(" before recombine STACK B\n");//
// 		print_int_list(*lst_b);//
