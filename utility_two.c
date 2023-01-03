/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:57:54 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/03 18:21:52 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mean(t_list *lst, int len)
{
	int			c;
	long int	sum;
	t_list		*temp;

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
	return (sum / len);
}

int	find_q_mean(t_list *lst, int len)
{
	int			c;
	long int	sum;
	long int	mean;
	t_list		*temp;

	c = 0;
	sum = 0;
	mean = find_mean(lst, len);
	if (!lst || len == 0)
		return (0);
	else
		temp = lst;
	if (len < 50)
		return (mean);
	while (temp && c < len)
	{
		if (*(int *)temp->data < mean)
		{
			sum += (*(int *)temp->data);
			c++;
		}
		temp = temp->next;
	}
	return (sum / c);
}

int	more_to_move(t_list **lst, int pivot, int len)
{
	t_list	*temp;

	if (!lst || !(*lst))
		return (0);
	temp = *lst;
	while (temp && len)
	{
		if (*(int *)temp->data > pivot)
			return (1);
		temp = temp->next;
		len--;
	}
	return (0);
}
