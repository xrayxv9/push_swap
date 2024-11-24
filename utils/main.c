// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.c                                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/10/26 22:12:25 by xray              #+#    #+#             //
//   Updated: 2024/10/26 22:25:06 by xray             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "ft_utils.h"
void	print_stack(t_list *stack1)
{
	t_list	*curr;

	curr = stack1;
	if (!stack1)
		return ;
	while (curr)
	{
		ft_printf("%d |\n", curr->content);
		curr = curr->next;
	}
	ft_printf("_____________________\n");
}

int main(int argc, char **argv)
{
	t_list	*l;

	if (argc < 2)
	{
		ft_printf("Could you please give me something to sort ?");
		return (-1);
	}
	l = parsing(argc, argv);
	print_stack(l);
}
