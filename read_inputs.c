/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:58:36 by jebouche          #+#    #+#             */
/*   Updated: 2023/01/04 15:32:54 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char *to_check)
{
	size_t	i;

	i = 0;
	if ((to_check[0] == '-' || to_check[0] == '+') && ft_isdigit(to_check[1]))
		i++;
	while (to_check[i] && ft_isdigit(to_check[i]))
		i++;
	if (ft_strlen(to_check) == i)
		return (1);
	return (0);
}

static int	check_dups(t_list	**stack)
{
	t_list	*temp1;
	t_list	*temp2;
	int		to_check;

	if (!stack)
		return (0);
	temp1 = *stack;
	temp2 = (*stack)->next;
	while (temp1 && temp2)
	{
		to_check = *(int *)temp1->data;
		while (temp2)
		{
			if (to_check == *(int *)temp2->data)
				return (0);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
		temp2 = temp1->next;
	}
	return (1);
}

static int	validate_num(char *str)
{	
	int	num;

	if (!is_int(str))
		return (0);
	num = ft_atoi(str);
	if (num < 0 && str[0] != '-')
		return (0);
	else if (num >= 0 && str[0] == '-')
		return (0);
	return (1);
}

static int	generate_stack(char **strs, t_list **head, int arg_str)
{
	t_list	*new;
	int		i;
	int		*num_content;

	i = 0;
	if (arg_str == 0)
		i = 1;
	if (!head)
		return (0);
	while (strs[i])
	{
		if (!validate_num(strs[i]))
			return (0);
		num_content = make_int_content(ft_atoi(strs[i]));
		new = ft_lstnew(num_content);
		if (!new || !num_content)
			return (0);
		ft_lstadd_back(head, new);
		i++;
	}
	if (!check_dups(head))
		return (0);
	return (1);
}

void	read_inputs(t_list **head, int argc, char **argv)
{
	char	**arr;
	int		gen_result;

	gen_result = 0;
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		arr = ft_split(argv[1], ' ');
		if (arr)
		{
			gen_result = generate_stack(arr, head, 1);
			free_array(arr);
		}
		else
			gen_result = 0;
	}
	else
		gen_result = generate_stack(argv, head, 0);
	if (gen_result == 0)
	{
		ft_lstclear(head, &del_int_content);
		head = NULL;
	}
}
