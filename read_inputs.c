/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:58:36 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/13 12:10:24 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char *to_check)
{
	int	i;

	i = 0;
	while (to_check[i] && ft_isdigit(to_check[i]))
		i++;
	if (ft_strlen(to_check) == i)
		return (1);
	return (0);
}

static int	generate_stack(char **strs, t_list **head, int arg_str)
{
	t_list	*new;
	int		i;
	int		num;

	if (arg_str == 0)
		i = 1;
	else
		i = 0;
	if (!head)
		return (0);
	num = 0;
	while (strs[i])
	{
		if (!is_int(strs[i]))
			return (0);
		num = ft_atoi(strs[i]);
		new = ft_lstnew(make_content(num));
		if (!new)
			return (0);
		ft_lstadd_back(head, new);
		i++;
	}
	return (1);
}

t_list	*read_inputs(int argc, char **argv)
{
	t_list	*head;
	char	**arr;
	int		gen_result;

	head = NULL;
	gen_result = 0;
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		arr = ft_split(argv[1], ' ');
		gen_result = generate_stack(arr, &head, 1);
	}
	else
		gen_result = generate_stack(argv, &head, 0);
	if (gen_result == 0)
	{
		ft_lstclear(&head, &del_content);
		head = NULL;
		return (head);
	}
	return (head);
}
