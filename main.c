/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:31:21 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/03 15:04:07 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	*moves;

	head = NULL;
	if (argc > 1)
		read_inputs(&head, argc, argv);
	if (head == NULL)
		ft_putendl_fd("Error", 2);
	else
	{
		moves = sort_list(&head);
		// print_str_list(moves);
		sanitize_moves(&moves);
		print_sanitized(moves);
		ft_lstclear(&head, &del_int_content);
		ft_lstclear(&moves, &del_str_content);
	}
	return (0);
}
