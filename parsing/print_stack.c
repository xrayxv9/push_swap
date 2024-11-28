/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:44:27 by xray              #+#    #+#             */
/*   Updated: 2024/11/28 15:44:41 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int	is_sorted(t_list *s)
{
	t_list	*curr;

	curr = s;
	while (curr->next)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	find_greater(t_list *s)
{
	t_list	*curr;
	int		tmp;
	int		len;

	curr = s;
	len = ft_recur(curr->content, NULL, 0); 
	curr = curr->next;
	while (curr)
	{
		tmp = ft_recur(curr->content, NULL, 0);
		if (len < tmp)
			len = tmp;
		curr = curr->next;
	}
	return (len);
}


void	print_stack(t_list *stack1)
{
	t_list	*curr;
	int		greater;
	int		i;

	greater = find_greater(stack1);
	curr = stack1;
	if (!stack1)
		return ;
	while (curr)
	{
		ft_printf("%d", curr->content);
		i = ft_recur(curr->content, NULL, 0);
		while (greater - i > 0)
		{
			ft_printf(" ");
			i++;
		}
		ft_printf(" |\n");
		curr = curr->next;
	}
}


