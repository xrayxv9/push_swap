/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:05:06 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/28 11:03:22 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

void	push(t_list **stack, t_list **stack_to)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_front(stack_to, tmp);
}

void	rotate(t_list **stack)
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
}

void	rrotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*curr;

	tmp = *stack;
	curr = *stack;
	while (curr->next->next)
		curr = curr->next;
	curr->next->next = tmp;
	(*stack) = curr->next;
	curr->next = NULL;
}

void	swap(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = (*stack);
	(*stack) = tmp;
}
