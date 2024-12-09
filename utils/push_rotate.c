/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:05:06 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/09 10:49:49 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

void	push(t_list **stack, t_list **stack_to, int code)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_front(stack_to, tmp);
	if (code == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	rotate(t_list **stack, int code)
{
	t_list	*curr;
	t_list	*tmp;

	tmp = *stack;
	curr = *stack;
	*stack = (*stack)->next;
	while (curr->next)
		curr = curr->next;
	curr->next = tmp;
	tmp->next = NULL;
	if (code == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}
