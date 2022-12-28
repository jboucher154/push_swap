/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:55:27 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/28 17:26:31 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mean(t_list *lst, int len)
{
	int c;
	long int	sum;
	t_list	*temp;

	c = 0;
	sum = 0;
	if (!lst || len == 0)
		return (0);
	else
		temp = lst;
	while (temp && c < len)
	{
		sum += (*(int *)temp->data);
		temp = temp->next;
		c++;
	}
	// ft_printf("SUM: %i ", sum );
	// ft_printf("LEN : %i ", len);
	// ft_printf("MEAN : %i \n", sum / len);
	return (sum / len);
}

int	partition(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	int len;
	int	size;
	int	pivot;
	// int	remaining;

	len = ft_lstsize(*lst_a);
	size = 0;
	// ft_printf("\ntop of PARTITION\n");
	// ft_printf("\nSTACK A\n");//
	// print_int_list(*lst_a);//
	// ft_printf("STACK B\n");//
	// print_int_list(*lst_b);//
	// ft_printf("moves\n");//
	// print_str_list(*moves);//
	
	if (len == 2) //causing floating point...
		return (size);
	pivot = find_mean(*lst_a, len);
	// ft_printf("PIVOT : %i\n", pivot);//
	while (len) //changed to > 2 took it away now.
	{
		if (*(int *)(*lst_a)->data < pivot)
		{
			add_move(moves, pb(lst_b, lst_a));
			size++;
		}
		else
			add_move(moves, ra(lst_a));
		len--;
	}
	return (size);
}

void	divide(t_list **moves, t_list **lst_a, t_list **lst_b, t_list **part_sizes)
{
	t_list *new;
	int		size;
	
	size = 1;
	while (size)
	{
		size = partition(moves, lst_a, lst_b);
		if (size == 0)
			break ;
		new = ft_lstnew(make_int_content(size));
		if (!new)
			break ; //print error and exit
		ft_lstadd_front(part_sizes, new);
		
	}
}

t_list	*sort_list(t_list **lst_a)
{
	t_list	*lst_b;
	t_list	*moves;
	t_list	*part_sizes;
	// t_list	*new;

	lst_b = NULL;
	moves = NULL;
	part_sizes = NULL;
	if (!lst_a && !(*lst_a))
		return (NULL);
	if ((*lst_a)->next == NULL || check_if_sorted(*lst_a))
		return (moves);
	else
	{
		divide(&moves, lst_a, &lst_b, &part_sizes);
		if ((*lst_a)->next && *((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data))
		{
			if (lst_b && lst_b->next && *(int *)lst_b->data < *(int *)lst_b->next->data)
				add_move(&moves, ss(lst_a, &lst_b));
			else
				add_move(&moves, sa(lst_a));
		}
		// ft_printf("\nafter divide\n");
		// ft_printf("\nSTACK A\n");//
		// print_int_list(*lst_a);//
		// ft_printf("STACK B\n");//
		// print_int_list(lst_b);//
		// ft_printf("moves\n");//
		// print_str_list(moves);//
		// ft_printf("PARTION SIZES\n");//
		// print_int_list(part_sizes);//

		conquer(&moves, lst_a, &lst_b, &part_sizes);

		// ft_printf("\nafter conquer\n");
		// ft_printf("\nSTACK A\n");//
		// print_int_list(*lst_a);//
		// ft_printf("STACK B\n");//
		// print_int_list(lst_b);//
		// ft_printf("moves\n");//
		// print_str_list(moves);//
		// ft_printf("PARTION SIZES\n");//
		// print_int_list(part_sizes);//
	}
	// if (part_sizes)
	// 	ft_lstclear(&part_sizes, &del_int_content);
	// if (lst_b)
	// 	ft_lstclear(&lst_b, &del_int_content);
	return (moves);
}

		// ft_printf("\nafter divide\n");
		// ft_printf("\nSTACK A\n");//
		// print_int_list(*lst_a);//
		// ft_printf("STACK B\n");//
		// print_int_list(lst_b);//
		// ft_printf("moves\n");//
		// print_str_list(moves);//
		// ft_printf("PARTION SIZES\n");//
		// print_int_list(part_sizes);//





// int	find_mid(t_list *lst, int len)
// {
// 	int pivot;
// 	t_list	*temp;

// 	if (!lst)
// 		temp = NULL;
// 	else
// 		temp = lst;
	
// 	pivot = len / 2 + 1;
// 	while (temp && len > pivot)
// 	{
// 		temp = temp->next;
// 		len--;
// 	}
// 	return (*(int *)temp->data);
// }