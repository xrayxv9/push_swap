// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_utils_node_remains.c                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/10/27 15:11:11 by xray              #+#    #+#             //
//   Updated: 2024/10/28 01:30:21 by xray             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "ft_utils.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	if (!lst)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = n;
	else
		*lst = n;
}

t_list	*ft_lstmap(int *lst)
{
	t_list	*result;
	t_list	*new_content;
	int		i;

	i = 0;
	if (!lst)
		return (NULL);
	result = NULL;
	while (lst[i])
	{
		new_content = ft_lstnew(lst[i]);
		if (!new_content)
		{
			ft_lstclear(&result);
			free(new_content);
			return (NULL);
		}

		ft_lstadd_back(&result, new_content);
		i++;
	}
	return (result);
}
