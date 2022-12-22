/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:31:21 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/22 17:15:54 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <assert.h>//

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
		// print_int_list(head);
		moves = sort_list(&head);
		// print_str_list(moves);

		// ft_printf("\nsanitized\n");
		print_sanitized_moves(&moves);
		// print_str_list(moves);
		
		ft_printf("\nAFTER SORT\n");
		print_int_list(head);
		ft_lstclear(&head, &del_int_content);
		ft_lstclear(&moves, &del_str_content);
	}
	return (0);
}

//this does not work with the checker...
// 4 67 3 87 23 6 1 90 432 6543123 341 2 1
// commands not printing properly/////
// but the following does 
// 4 67 3 87 23 6 1 90 432 6543123 341 2 10
// 4 67 3 87 23 6 1 90 432 6543123 341 2