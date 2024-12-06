/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:41:22 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/06 12:13:00 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

void	minus(int	nbr, t_dual *dual, t_list **sa, int i)
{
	t_list	*curr;

	curr = *sa;
	while (i--)
	{
		if (curr->content > nbr)
			curr->index++;
		else if (curr->content < nbr)
			curr->index--;
		curr = curr->next;
	}
}

void	give_index(t_list	**sa)
{
	int	i;
	int	max;
	t_dual dual;
	t_list	*curr;

	curr = *sa;
	dual.bigger = 0;
	dual.smaller = 0;
	i = 0;
	max = ft_lstlen(*sa);
	while (i < max)
	{
		if (curr->content > dual.smaller)
			adapt(curr->content, &dual, sa, i - 1);
		i++;
	}
}
