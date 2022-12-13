/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:36:41 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/09 12:47:17 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*temp;

	len = 0;
	if (!lst)
		return (len);
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}
