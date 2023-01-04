/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:31:21 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/04 11:44:25 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_sanitized(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		while (temp && !ft_strncmp(temp->data, "x", 1))
			temp = temp->next;
		if (!temp)
			break ;
		ft_printf("%s\n", temp->data);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	*moves;

	head = NULL;
	if (argc > 1)
		read_inputs(&head, argc, argv);
	if (head == NULL)
		error();
	else
	{
		moves = sort_list(&head);
		// print_str_list(moves);
		// ft_printf("sanitized\n");
		sanitize_moves(&moves);
		print_sanitized(moves);
		ft_lstclear(&head, &del_int_content);
		ft_lstclear(&moves, &del_str_content);
	}
	return (0);
}
