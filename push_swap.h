/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:26:34 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/21 11:55:53 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"


t_list	*read_inputs(int argc, char **argv);
t_list	*sort_list(t_list **lst_a);

//sorting utility
void	add_move(t_list **moves, char *move);
void	check_swaps_a(t_list **moves, t_list **lst_a, t_list **lst_b, int *ab_len);
void	check_swaps_b(t_list **moves, t_list **lst_a, t_list **lst_b, int *ab_len);

//moves
char	*sa(t_list **head); 
char	*sb(t_list **head); 
char	*ss(t_list **head1, t_list **head2);
char	*pa(t_list **dst, t_list **src);
char	*pb(t_list **dst, t_list **src);
char	*ra(t_list **head);
char	*rb(t_list **head);
char	*rr(t_list **head1, t_list **head2);
char	*rra(t_list **head);
char	*rrb(t_list **head);
char	*rrr(t_list **head1, t_list **head2);

//list utilities
int		*make_int_content(int num);
void	del_int_content(void *data);
void	del_str_content(void *data);
void	print_int_list(t_list *head);
t_list	*lst_pop(t_list **to_remove);
void	print_str_list(t_list *head);

//checking utiility
int		check_if_sorted(t_list *head);
int		check_if_revsorted(t_list *head);

#endif