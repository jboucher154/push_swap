/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:31:21 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/15 15:40:39 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_list *lst_a)
{
	t_list	*lst_b;

	lst_b = NULL;
	if (lst_a->next == NULL) // or just check if sorted here...
		return ;//list is already sorted
	else
	{
		return ;
		//check if sorted already?
		//otherwse start the sorting?
	}
}

int	main(int argc, char **argv)
{
	t_list	*head;
	// int		sorted;

	head = NULL;
	if (argc > 1)
		head = read_inputs(argc, argv);
	if (head == NULL)
		ft_printf("Error\n");
	// sorted = check_if_sorted(head);
	// ft_printf("sorted: %i\n", sorted);
	print_list(head);
	ft_lstclear(&head, &del_int_content);
	return (0);
}
