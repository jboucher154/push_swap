/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:58:36 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/28 16:32:12 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char *to_check)
{
	size_t	i;

	i = 0;
	if ((to_check[0] == '-' || to_check[0] == '+')&& ft_isdigit(to_check[1]))
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

static int	check_num(int num, char *str)
{
	if (num < 0 && str[0] != '-')
		return (0);
	else if (num > 0 && str[0] == '-')
		return (0);
	return (1);
}

static int	generate_stack(char **strs, t_list **head, int arg_str)
{
	t_list	*new;
	int		i;
	int		num;

	i = 0;
	if (arg_str == 0)
		i = 1;
	if (!head)
		return (0);
	num = 0;
	while (strs[i])
	{
		if (!is_int(strs[i]))
			return (0);
		num = ft_atoi(strs[i]);
		if (!check_num(num, strs[i]))
			return (0);
		new = ft_lstnew(make_int_content(num));
		if (!new)
			return (0);
		ft_lstadd_back(head, new);
		i++;
	}
	if (!check_dups(head))
		return (0);
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
		ft_lstclear(&head, &del_int_content);
		head = NULL;
	}
	return (head);
}


// static int	check_errors(t_list	**stack)
// {
// 	t_list	*temp1;
// 	t_list	*temp2;
// 	int		to_check;

// 	if (!stack)
// 		return (0);
// 	temp1 = *stack;
// 	temp2 = (*stack)->next;
// 	while (temp1 && temp2)
// 	{
// 		to_check = *(int *)temp1->data;
// 		while (temp2)
// 		{
// 			if (to_check == *(int *)temp2->data)
// 				return (0);
// 			else if (to_check > INT_MAX || to_check < INT_MIN || \
// 				*(int *)temp2->data > INT_MAX || *(int *)temp2->data > INT_MIN)
// 				return (0);
// 			temp2 = temp2->next;
// 		}
// 		temp1 = temp1->next;
// 		temp2 = temp1->next;
// 	}
// 	return (1);
// }