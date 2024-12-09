/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:41:07 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/09 11:16:26 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

int	greater_index(t_list *sa)
{
	t_list	*curr;
	int		max;

	curr = sa;
	max = curr->index;
	while (curr)
	{
		if (curr->index > max)
			max = curr->index;
		curr = curr->next;
	}
	return (max);
}

int	max_bytes(t_list *sa)
{
	int		max;
	int		bytes;

	max = greater_index(sa);
	bytes = 0;
	while (max)
	{
		bytes++;
		max = max >> 1;
	}
	return (bytes);
}
