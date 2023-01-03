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

int	find_q_mean(t_list *lst, int len)
{
	int c;
	long int	sum;
	long int	mean;
	t_list	*temp;

	c = 0;
	sum = 0;
	mean = find_mean(lst, len);
	if (!lst || len == 0)
		return (0);
	else
		temp = lst;
	while (temp && c < len)
	{
		if (*(int *)temp->data < mean)
		{
			sum += (*(int *)temp->data);
			c++;
		}
		temp = temp->next;
	}
	// ft_printf("SUM: %i ", sum );
	// ft_printf("LEN : %i ", len);
	// ft_printf("MEAN : %i \n", sum / len);
	return (sum / len);
}

int	more_to_move(t_list **lst, int pivot, int len)
{
	t_list	*temp;

	if (!lst || !(*lst))
		return (0);
	temp = *lst;
	while(temp && len)
	{
		if (*(int *)temp->data > pivot)
			return (1);
		temp = temp->next;
		len--;
	}
	return (0);
}

int	find_next_move(t_list **moves, t_list **lst_a, int pivot) //for now work iwht just one pivot point, check for values less than
{
	int	len;
	int	location;
	t_list *temp;

	len = ft_lstsize(*lst_a);
	location = 0;
	temp = *lst_a;
	while (temp)
	{
		location++;
		if (*(int *)temp->data < pivot)
			break ;
		temp = temp->next;
	}
	if (temp == NULL)
		return (0);
	else if (location <= len / 2)
	{
		rotate_a(moves, lst_a, location - 1);
		return (location - 1);
	}
	else
	{
		rev_rotate_a(moves, lst_a, len - location + 1);
		return (len - location + 1);
	}	
}

int	partition(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	int len;
	int	size;
	int	pivot;
	int	remaining;

	len = ft_lstsize(*lst_a);
	remaining = 1;
	size = 0;
	// ft_printf("\ntop of PARTITION\n");
	// ft_printf("\nSTACK A\n");//
	// print_int_list(*lst_a);//
	// ft_printf("STACK B\n");//
	// print_int_list(*lst_b);//
	// ft_printf("moves\n");//
	// print_str_list(*moves);//
	if (len == 3)//changed from 2 to 3
		return (size);
	if (len > 50)
		pivot = find_q_mean(*lst_a, len);
	else
		pivot = find_mean(*lst_a, len);
	// ft_printf("PIVOT : %i\n", pivot);//
	while (len > 3 && remaining)
	{
		if (*(int *)(*lst_a)->data < pivot)
		{
			add_move(moves, pb(lst_b, lst_a));
			size++;
			len--;
		}
		// else if (!more_to_move(lst_a, pivot, len)) //changed from to eval...
		// 	break ;
		else
		{
			remaining = find_next_move(moves, lst_a, pivot);
		}
			// add_move(moves, ra(lst_a));
		// to_eval--;
	}
	return (size);
}
//not tested......
int	*find_pivot(t_list **lst_a, int num_parts)
{
	t_list *temp;
	// int 	smallest;
	int		largest;
	// int		chunk;
	int		pivot_tools[2];

	temp = *lst_a;
	pivot_tools[0] = *(int *)temp->data;
	largest = pivot_tools[0];
	while (temp)
	{
		if (*(int *)temp->data < pivot_tools[0])
			pivot_tools[0] = *(int *)temp->data;
		if (*(int *)temp->data > largest)
			largest = *(int *)temp->data;
		temp = temp->next;
	}
	pivot_tools[1] = (largest - pivot_tools[0]) / num_parts;
	return (pivot_tools);
}

// //determine partitioning needs here, number and size...
// void	divide(t_list **moves, t_list **lst_a, t_list **lst_b, t_list **part_sizes)
// {
// 	t_list *new;
// 	int		size;
// 	// int		pivot;//find the smalles value as starting point, second in partition tool
// 	int		partition_tool[2];//determine based on the lst size
// 	int		len;
	
// 	size = 1;
// 	len = ft_lstsize(*lst_a);
// 	partition_tool[0] = len / ((len / 150) * 5); //not the right way....
// 	partition_tool[1] = find_pivot(lst_a, partition_tool[0]);
// 	while (size)
// 	{
// 		size = partition(moves, lst_a, lst_b);
// 		if (size == 0)
// 			break ;
// 		new = ft_lstnew(make_int_content(size));
// 		if (!new)
// 			break ; //print error and exit
// 		ft_lstadd_front(part_sizes, new);
		
// 	}
// }

//determine partitioning needs here, number and size...
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

void	sort_three(t_list **moves, t_list **lst_a)
{
	if (*(int *)(*lst_a)->data < *(int *)(*lst_a)->next->data)//sorted
	{
		if (*(int *)(*lst_a)->data > *(int *)(*lst_a)->next->next->data)//first is greater than last
			add_move(moves, rra(lst_a)); //bring last to first pos
	}
	else if (*(int *)(*lst_a)->data > *(int *)(*lst_a)->next->data)// not sorted
	{
		if (*(int *)(*lst_a)->data > *(int *)(*lst_a)->next->next->data)//first less than last
			add_move(moves, ra(lst_a)); //send to bot
	}
	if (!check_if_sorted(*lst_a))
	{
		add_move(moves, sa(lst_a));
		sort_three(moves, lst_a);
	}
}

void	sort_two(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a)->next && *((int *)(*lst_a)->data) > *((int *)(*lst_a)->next->data))
	{
		if (lst_b && (*lst_b)->next && *(int *)(*lst_b)->data < *(int *)(*lst_b)->next->data)
			add_move(moves, ss(lst_a, lst_b));
		else
			add_move(moves, sa(lst_a));
	}
}

t_list	*sort_list(t_list **lst_a)
{
	t_list	*lst_b;
	t_list	*moves;
	t_list	*part_sizes;
	int		len;

	lst_b = NULL;
	moves = NULL;
	part_sizes = NULL;
	if (!lst_a && !(*lst_a))
		return (NULL);
	len = ft_lstsize(*lst_a);
	if ((*lst_a)->next == NULL || check_if_sorted(*lst_a))
		return (moves);
	else
	{
		if (len > 3)
			divide(&moves, lst_a, &lst_b, &part_sizes);
		if (len == 2)
			sort_two(&moves, lst_a, &lst_b);
		else
			sort_three(&moves, lst_a); //or sort two if len is two...
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
	ft_lstclear(&part_sizes, &del_int_content);
	// if (lst_b)
	// 	ft_lstclear(&lst_b, &del_int_content);
	return (moves);
}

		// ft_printf("\nTOP OF SORT 3\n");
		// ft_printf("\nSTACK A\n");//
		// print_int_list(*lst_a);//
		// ft_printf("moves\n");//
		// print_str_list(moves);//
		





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

/* only make a move if you really need to. add checking for values that need to be moved 
before just rotating thorugh the whole of the list

maybe figure out a way to do the ss... when checking the a swaps. will need to be 
limited by the partitoins, or will that mater, as all the value in one partition will 
be above values in the other so it shouldn't matter?

if I rotated then rev rotated, cancel them out... */