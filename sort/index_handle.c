/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:41:22 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/09 09:53:32 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

t_list	*find_node(t_list *sa, int content)
{
	t_list *curr;

	curr = sa;
	while (curr)
	{
		if (curr->content == content)
		{
			return (curr);
		}
		curr = curr->next;
	}
	return (NULL);
}

void	change_index(t_list **sa, int i, t_dual *dual)
{
	t_list	*curr;

	curr = *sa;
	while (curr)
	{
		if (curr->content < dual->smaller && !curr->index)
			dual->smaller = curr->content;
		else if (find_node(*sa, dual->smaller)->index)
			dual->smaller = curr->content;
		else if (curr->content == dual->smaller &&
				find_node(*sa, dual->smaller)->index)
			dual->smaller = curr->content;
		curr = curr->next;
	}
	find_node(*sa, dual->smaller)->index = i;
}

void	give_index(t_list	**sa, t_list **sb)
{
	int		i;
	int		max;
	t_dual	dual;
	t_list	*curr;

	i = 1;
	curr = *sa;
	dual.smaller = (*sa)->content;
	max = ft_lstlen(*sa);
	while (i <= max)
	{
		change_index(sa, i, &dual);		
		i++;
		curr = curr->next;
	}
	radix(sa, sb);
}
