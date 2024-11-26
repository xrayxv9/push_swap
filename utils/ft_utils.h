// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_utils.h                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/10/27 00:40:02 by xray              #+#    #+#             //
//   Updated: 2024/10/28 01:30:34 by xray             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdlib.h>
# include "../printf/ft_printf.h"
# include <stddef.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

t_list	*error(int error, t_list *l);

t_list	*ft_lstmap(int *lst);

t_list	*parsing(int argc, char **t, t_list *l);

void	ft_lstadd_back(t_list **lst, t_list *n);

t_list	*ft_lstnew(int content);

void	ft_lstadd_front(t_list **lst, t_list *n);

void	ft_lstdelone(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstclear(t_list **lst);

int		ft_lstlen(t_list *l);


#endif
