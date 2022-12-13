/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:31:21 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/13 12:09:50 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*head;

	head = NULL;
	if (argc > 1)
		head = read_inputs(argc, argv);
	if (head == NULL)
		ft_printf("Error\n");
	print_list(head);
	ft_lstclear(&head, &del_content);
	return (0);
}
