/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:41:22 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/06 14:52:23 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

void	adapt(int	nbr, t_dual *dual, t_list **sa, int i)
{
	t_list	*curr;

	curr = *sa;
	if (dual->code == 1)
		dual->smaller = nbr;
	else 
		dual->bigger = nbr;
	while (i-- > 0)
	{
		if (curr->content > nbr)
			curr->index++;
		else if (curr->content < nbr)
			curr->index--;
		curr = curr->next;
	}
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
	t_dual dual;
	t_list	*curr;

	curr = *sa;
	dual.bigger = 0;
	dual.smaller = 0;
	i = 0;
	max = ft_lstlen(*sa);
	while (i < max)
	{
		curr->index = i;
		if (curr->content < dual.smaller)
		{
			dual.code = 1;
			adapt(curr->content, &dual, sa, i - 1);
		}
		else if (curr->content > dual.bigger)
		{
			dual.code = 2;
			adapt(curr->content, &dual, sa, i - 1);
		}
		i++;
	}
	print_index(*sa);
}
