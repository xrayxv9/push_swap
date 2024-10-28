// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_utils_node.c                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/10/27 14:48:09 by xray              #+#    #+#             //
//   Updated: 2024/10/27 15:24:00 by xray             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "ft_utils.h"

t_list	*ft_lstnew(int content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

void	ft_lstadd_front(t_list **lst, t_list *n)
{
	if (!lst)
		return ;
	n->next = *lst;
	*lst = n;
}

void	ft_lstdelone(t_list *lst)
{
	int	content;
	
	content = lst->content;
	if (!lst)
		return ;
	free(lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*curr;

	while (*lst)
	{
		curr = (*lst)->next;
		ft_lstdelone(*lst);
		(*lst) = curr;
	}
	free(*lst);
	(*lst) = NULL;
}
