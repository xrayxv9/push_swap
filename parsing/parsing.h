/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:14:15 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/28 15:45:31 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include "../printf/ft_printf.h"
# include <stddef.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int			check_m_p(char *s);

void		add(int *i, int *space, int *sign, char c);

int			check_strings(char *s);

int			is_sorted(t_list *s);

int			find_greater(t_list *s);

void		print_stack(t_list *stack1);

long long	ft_atoll(char *s, int *i, int *space);

int			ft_strlen_space(char *s);

t_list		*error(t_list *l);

t_list		*ft_lstmap(int *lst);

t_list		*parsing(int argc, char **t, t_list *l);

void		ft_lstadd_back(t_list **lst, t_list *n);

t_list		*ft_lstnew(int content);

void		ft_lstadd_front(t_list **lst, t_list *n);

void		ft_lstdelone(t_list *lst);

t_list		*ft_lstlast(t_list *lst);

void		ft_lstclear(t_list **lst);

int			ft_lstlen(t_list *l);

int			ft_recur(int n, char *ptr, int l);

#endif
