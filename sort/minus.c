/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:50:01 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/19 10:39:55 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

void	push_smaller(t_list **sa, t_list **sb)
{
	int		i;

	i = 0;
	while (i != 2)
	{
		while (((*sa)->index != 1 && i == 0) || ((*sa)->index != 2 && i == 1))
		{
			if (ft_lstlast(*sa)->index == 1)
				rrotate(sa, 'a');
			else
				rotate(sa, 'a');
		}
		push(sa, sb, 'b');
		i++;
	}
}

void	handle_three(t_list **sa, int code)
{
	if (!is_sorted(*sa))
	{
		if (((*sa)->index == 3 && (code == 1)) || (*sa)->index == 1)
			swap(sa, 'a');
		if (((*sa)->index > (*sa)->next->index)
			&& (((*sa)->index == 4 && code == 1) || (*sa)->index == 2))
			swap(sa, 'a');
		if (((*sa)->index == 4 && (code == 1)) || (*sa)->index == 2)
			rotate(sa, 'a');
		if (((*sa)->index == 5 && (code == 1))
			|| ((*sa)->index == 3 && code == 2))
			rotate(sa, 'a');
		if (((*sa)->index == 4 && (code == 1)) || (*sa)->index == 2)
			swap(sa, 'a');
	}
}

void	handle_two(t_list **sa)
{
	if (!is_sorted(*sa))
		swap(sa, 'a');
}

void	handler(t_list	**sa, t_list **sb, int len)
{
	int		l;

	if (len == 2)
		rotate(sa, 'a');
	else if (len == 3)
		handle_three(sa, 2);
	else if (len > 3)
	{
		push_smaller(sa, sb);
		l = ft_lstlen(*sa);
		if (l == 3)
			handle_three(sa, 1);
		else
			handle_two(sa);
		if (sb)
		{
			push(sb, sa, 'a');
			push(sb, sa, 'a');
		}
	}
}
