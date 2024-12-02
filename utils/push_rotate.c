/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:05:06 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/02 10:16:00 by xray             ###   ########.fr       */
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
	if (code == 1)
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
	if (code == 1)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	rrotate(t_list **stack, int code)
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
	if (code == 1)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}

void	swap(t_list **stack, int code)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	if (code == 1)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}
