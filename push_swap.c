/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:31:21 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/20 18:33:18 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	*moves;

	head = NULL;
	if (argc > 1)
		head = read_inputs(argc, argv);
	if (head == NULL)
		ft_printf("Error\n");
	else
	{
		// ft_printf("\nbefore moves\n");//
		moves = sort_list(&head);
		// if (moves)
		// 	print_str_list(moves);
		ft_printf("\nAFTER SORT\n");
		print_int_list(head);
		ft_lstclear(&head, &del_int_content);
		ft_lstclear(&moves, &del_str_content);
	}
	return (0);
}

//this is breaking my code....
// 1 3 2 5 4 3 90 1 7 34 42 12 34567 891 2 1 1 
// 890 4 1 3 2 5 4 3 90 1 7 34 42 12 34567 891 1 6 567
// 890 34567 891 1 6 567 // remove any one of these and it works...
//but not this
// 890 4 1 3 2 5 4 3 90 1 7 34 42 12 34567 891 1 6