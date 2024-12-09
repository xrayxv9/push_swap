/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:02:11 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/09 10:48:54 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

void	pb(t_list **sa, t_list **sb, int mask)
{
	int	len;

	len = ft_lstlen(*sb);
	while (len-- && !is_sorted(*sa))
	{
		if ((*sb)->index >> mask & 1)
			push(sb, sa, 'a');
		else
			rotate(sb, 'b');
	}
	if (is_sorted(*sa))
		while (*sb)
			push(sb, sa, 'a');
}

void	radix(t_list **sa, t_list **sb)
{
	int		mask;
	int		bytes;
	int		len;

	mask = 0;
	bytes = max_bytes(*sa);
	while (bytes >= mask)
	{
		len = ft_lstlen(*sa);
		while (len-- && !is_sorted(*sa))
		{
			if ((*sa)->index >> mask & 1)
				rotate(sa, 'a');
			else
				push(sa, sb, 'b');
		}
		mask++;
		pb(sa, sb, mask);
	}
}
