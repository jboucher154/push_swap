/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:00:21 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/03 18:11:30 by jebouche         ###   ########.fr       */
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

void	del_str_content(void *data)
{
	data = NULL;
}

void	free_array(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}