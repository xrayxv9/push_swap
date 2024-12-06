/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:41:22 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/06 16:47:57 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

int	smaller_index(t_list **sa)
{
	t_list	*curr;
	t_list	*tmp;

	tmp = *sa;
	curr = (*sa)->next;
	while (curr)
	{
		if (curr->content < tmp->content && !curr->index)
			tmp = curr;
		curr = curr->next;
	}
	return (tmp->content);
}

void	change_index(int nbr, t_list **sa, int i)
{
	t_list	*curr;

	curr = *sa;
	while (curr->content != nbr)
		curr = curr->next;
	curr->index = i;
}

void print_index(t_list *sa)
{
	t_list	*curr;

	curr = sa;
	while (curr)
	{
		ft_printf("%d = %d\n", curr->content, curr->index);
		curr = curr->next;
	}
}

void	give_index(t_list	**sa)
{
	int	i;
	int	max;

	i = 1;
	max = ft_lstlen(*sa);
	while (i <= max)
	{
		change_index(smaller_index(sa), sa, i);
	
		i++;
	}
	print_index(*sa);
}
