/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:26:34 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/16 14:22:40 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

t_list	*read_inputs(int argc, char **argv);
int		check_if_sorted(t_list *head);

//moves
char	*sa(t_list **head); //sa, sb
char	*sb(t_list **head); //sa, sb
char	*ss(t_list **head1, t_list **head2); //ss
char	*pa(t_list **dst, t_list **src); //pa, pb
char	*pb(t_list **dst, t_list **src);
char	*ra(t_list **head); //ra, rb
char	*rb(t_list **head);
char	*rr(t_list **head1, t_list **head2);
char	*rra(t_list **head); //rra, rrb
char	*rrb(t_list **head);
char	*rrr(t_list **head1, t_list **head2);

//list utilities
int		*make_int_content(int num);
void	del_int_content(void *data);
void	del_str_content(void *data);
void	print_list(t_list *head);
t_list	*lst_pop(t_list **to_remove);

#endif