/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:00:21 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/15 13:27:39 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_int_content(int num)
{
	int	*ptr;

	ptr = (int *) malloc(sizeof(int));
	*ptr = num;
	return (ptr);
}

void	del_int_content(void *data)
{
	free(data);
	data = NULL;
}

void	print_list(t_list *head)
{
	t_list	*temp;
	int		i;

	temp = head;
	i = 0;
	while (temp)
	{
		i = *((int *) temp->data);
		ft_printf("list data: %i\n", i);
		temp = temp->next;
	}
}
