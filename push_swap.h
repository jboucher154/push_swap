/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:26:34 by jebouche          #+#    #+#             */
/*   Updated: 2022/12/13 12:02:42 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

t_list	*read_inputs(int argc, char **argv);
int		*make_content(int num);
void	del_content(void *data);
void	print_list(t_list *head);

#endif