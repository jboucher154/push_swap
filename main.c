/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:31:21 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/04 15:33:04 by jebouche         ###   ########.fr       */
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
	else
		exit(1);
	if (head == NULL)
		error();
	else
	{
		moves = sort_list(&head);
		sanitize_moves(&moves);
		print_sanitized(moves);
		ft_lstclear(&head, &del_int_content);
		ft_lstclear(&moves, &del_str_content);
	}
	return (0);
}
