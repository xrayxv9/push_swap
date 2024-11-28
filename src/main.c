/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:59:35 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/28 11:29:19 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../parsing/parsing.h"
#include "../utils/utils.h"

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

int	main(int argc, char **argv)
{
	t_list	*s;
	t_list	*s2;
	
	s = NULL;
	s2 = NULL;
	if (argc < 2)
	{
		ft_printf("Could you please give me something to sort ?");
		return (-1);
	}
	s = parsing(argc, argv, s);
	if (!is_sorted(s))
	{
		for (int i = 0; i <= 1;i++)
		{
			ft_printf("stack_a :\n");
			print_stack(s);
			ft_printf("\n");
			//ft_printf("stack_b :\n");
			//print_stack(s2);
			if (i == 0)
			{
				ft_printf("=======================================\n");
				swap(&s);
			}
		}
	}
	else 
		ft_printf("The given list is Already sorted.");
	ft_lstclear(&s);
	ft_lstclear(&s2);
}
