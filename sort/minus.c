/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:50:01 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/12 17:27:29 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sort.h"

 

void	handle_under_five(t_list **sa, t_list **sb)
{
	
}

void	handler(t_list	**sa, t_list **sb, int len)
{
	t_list *curr;

	if (len == 2)
		rotate(sa, 'a');
	else 
	{
		handle_under_five(sa, sb);
	}
}
