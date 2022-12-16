/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:31:21 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/16 14:42:09 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_move(t_list **moves, t_list **lst_a, t_list **lst_b)
{
	
}

t_list	*sort_list(t_list *lst_a)
{
	t_list	*lst_b;
	t_list	*moves;
	t_list	*new;
	int		len;
	int 	i;

	lst_b = NULL;
	moves = NULL;
	i = 0;
	len = ft_lstsize(lst_a);
	if (check_if_sorted(lst_a)) //check if sorted here...
		return ;//list is already sorted
	else
	{
		while (i <= len / 2)
		{
			new = ft_lstnew(pb(&lst_b, &lst_a));
			if (new)
				ft_lstadd_back(&moves, new);
			else
			{
				return ;
				//free and exit;
			}
			i++;
		}
		// make_move();
		//otherwse start the sorting?
	}
	//free other lists before return
	return (moves);
}

int	main(int argc, char **argv)
{
	t_list	*head;

	head = NULL;
	if (argc > 1)
		head = read_inputs(argc, argv);
	if (head == NULL)
		ft_printf("Error\n");
	
	print_list(head);
	ft_lstclear(&head, &del_int_content);
	return (0);
}
